#include "SymbolTable.h"

void SymbolTable::EnterScope()
{
	stringmap map;
	table.push(stringmap);
}

void SymbolTable::ExitScope()
{
	if (table.empty())
	{
		return;
	}

	table.pop();
}

void SymbolTable::AddId(string id, string info)
{
	if (table.empty())
	{
		return;
	}

	stringmap map = (stringmap)table.top();
	map.insert({{id, info}});
}

string SymbolTable::Lookup(string sym)
{
	string info;

	if (table.empty())
	{
		return;
	}

	stack<stringmap> tempTable;

	while (!table.empty())
	{
		stringmap map = (stringmap)table.pop();
		tempTable.push(map);

		string tempInfo = map.at(sym);
		if (!tempInfo.empty())
		{
			info = tempInfo;
			break;
		}
	}

	while(!tempTable.empty())
	{
		stringmap map = (stringmap)tempTable.pop();
		table.push(map);
	}

	return info;
}

string SymbolTable::Probe(string sym)
{
	if (table.empty())
	{
		return;
	}

	stringmap map = (stringmap)table.top();

	return map.at(sym);
}

void SymbolTable::ErrorPrump_IdNotFound(int line, string id)
{
	cout << "Error in line: " << line << "\n" << " => " << "Identifier " << id << " Not Found!"; 
}

void SymbolTable::ErrorPrump_IdDuplicated(int line, string id)
{
	cout << "Error in line: " << line << "\n" << " => " << "Identifier " << id << " Duplicated!"; 
}