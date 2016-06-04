#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, string> stringmap;

class SymbolTable
{
	private:		
	stack<stringmap> table;

	public:

	void EnterScope();

	void ExitScope();

	void AddId(string id, string info);

	string Lookup(string sym);

	string Probe(string sym);

	void ErrorPrump_IdNotFound(int line, string id);

	void ErrorPrump_IdDuplicated(int line, string id);
};