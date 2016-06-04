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

void SymbolTable::AddId(String id, String info)
{
	if (table.empty())
	{
		return;
	}

	stringmap map = (stringmap)table.top();
	map.insert({{id, info}});
}

String SymbolTable::Lookup(String sym)
{
	String info;

	if (table.empty())
	{
		return;
	}

	stack<stringmap> tempTable;

	while (!table.empty())
	{
		stringmap map = (stringmap)table.pop();
		tempTable.push(map);

		String tempInfo = map.at(sym);
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

String SymbolTable::Probe(String sym)
{
	if (table.empty())
	{
		return;
	}

	stringmap map = (stringmap)table.top();

	return map.at(sym);
}

void SymbolTable::ErrorPrump_IdNotFound(int line, String id)
{
	cout << "Error in line: " << line << "\n" << " => " << "Identifier " << id << " Not Found!"; 
}

void SymbolTable::ErrorPrump_IdDuplicated(int line, String id)
{
	cout << "Error in line: " << line << "\n" << " => " << "Identifier " << id << " Duplicated!"; 
}