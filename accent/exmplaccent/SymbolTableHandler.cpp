#include <algorithm>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef string type_t; //type of variable 
typedef string variable_t; //name of variable
typedef string class_t; //name of 'class' (container)

const int NO_PARENT = -1; //top-most

typedef vector<class ClassSymbolTable> symbols_t; //we use vector to preserve order

// main class, it stores symbols of a single class, and references its parent
class ClassSymbolTable {

	class_t _name; //class name
	map<variable_t, type_t> _types; //map of variable types
	vector<variable_t> _variables; //we use this vector to preserve order
	symbols_t& _symbols; //reference to the symbol table
	int _parent_index = NO_PARENT; //reference to parent index in symbol vector


	//!! parent class, nullptr if top-level
	ClassSymbolTable* parent() const
	{
		return _parent_index != NO_PARENT ? &_symbols[_parent_index] : nullptr;
	}

	// does this class directly declares var ?
	bool declares_variable(const variable_t& var) const
	{
		return _types.find(var) != _types.end();
	}

	// print variable info in desired format
	void print_variable(const variable_t& var)
	{
		if (declares_variable(var))
		{
			cout << " -> <" << _types[var] << ", " << _name << ">";
		}
		if (parent())
		{
			parent()->print_variable(var);
		}
	}

	// traverse classes up to top-level and collect variables in order
	void collect_variables_to_print(vector<variable_t>& vars)
	{
		if (ClassSymbolTable* p = parent())
		{
			p->collect_variables_to_print(vars);
			// add variables defined on this level
			vector<variable_t> add_vars;
			for (size_t i = 0; i < _variables.size(); ++i)
			{
				if (find(vars.begin(), vars.end(), _variables[i]) == vars.end())
				{
					// defined on this level
					add_vars.push_back(_variables[i]);
				}
			}
			vars.insert(vars.end(), add_vars.begin(), add_vars.end());
		}
		else
		{
			//top-level
			vars = _variables;
		}
	}

	// get depth for indentation
	int get_depth() const
	{
		int depth = 0;
		for (ClassSymbolTable* p = parent(); p; p = p->parent())
		{
			++depth;
		}
		return depth;
	}


	static size_t s_max_class_name_length; //for printing
	public:
	// ctor
	ClassSymbolTable(const string& name, int parent_index, symbols_t& symbols) : _name(name), _parent_index(parent_index), _symbols(symbols)
	{
		s_max_class_name_length = max(s_max_class_name_length, name.length());
	}

	// add variable
	void add(const variable_t& var, const type_t& type)
	{
		_variables.push_back(var);
		_types[var] = type;
	}

	// print this class' vars in desired format
	void print()
	{
		cout.fill(' ');
		const int indent = get_depth() + s_max_class_name_length + 3 /*for ':' */;

		vector<variable_t> vars;
		collect_variables_to_print(vars);

		// print class name
		string classname = _name + ": ";

		cout.fill(' ');
		cout.width(indent);
		cout << classname;

		// print vars
		cout.width(0);
		cout << vars[0];
		print_variable(vars[0]);
		cout << endl;

		for (size_t i = 1; i < vars.size(); ++i)
		{
			cout.width(indent);
			cout << ' '; //pad before

			cout.width(0);
			cout << vars[i];
			print_variable(vars[i]);
			cout << endl;
		}

		cout.width(0);
	}
};

size_t ClassSymbolTable::s_max_class_name_length = 0;


int main(int argc, char* argv[])
{
	ifstream in("input1.txt");
	assert(in.is_open());

	symbols_t symbols;

	//collect symbols
	const char* delimiters = ":;{}";
	vector<string> current_tokens;
	string buffer;
	stack<int> class_stack; //to manage class hierarchy, we stack the classes' index in the symbol vector
	class_stack.push(NO_PARENT); //so we dont have to branch at first level

	while (in >> buffer)
	{
		size_t found = buffer.find_first_of(delimiters);
		current_tokens.push_back(buffer.substr(0, found)); //either whole or until delimiter

		if (found != string::npos)
		{ //delimiter found
			char delimiter = buffer[found];
			switch (delimiter)
			{
				case ':': //class name
					assert(current_tokens.size() == 1);
					{
						// add new class symbol table and refer to parent class
						symbols.emplace_back(current_tokens[0], class_stack.top(), symbols);
						// we rather store index in '{' for symmetric code
					}
				break;
			
				case '{': //block open
					assert(!symbols.empty());
					{
						class_stack.push(symbols.size()-1); //stack the index for nested classes
					}
				break;
			
				case '}': //block close
					assert(!class_stack.empty());
					{
						class_stack.pop(); //done with this class
					}
				break;
				
				case ';': //variable
					assert(!symbols.empty());
					assert(current_tokens.size() == 2);
					{
						// add variable to the current class symbol table
						ClassSymbolTable& current_class = symbols.back();
						current_class.add(current_tokens[1], current_tokens[0]);
					}
				break;
			}

			//put back the remaining characters
			current_tokens.clear();
			if (found < buffer.size() - 1)
			{
				current_tokens.push_back(buffer.substr(found + 1));
			}

		}

	}

	assert(class_stack.size() == 1 && class_stack.top() == NO_PARENT); //just to be sure

	for (ClassSymbolTable& c : symbols)
	{
		c.print();
	}

	cout << "." << endl;
	return 0;
}