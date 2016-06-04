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

	void AddId(String id, String info);

	String Lookup(String sym);

	String Probe(String sym);

	void ErrorPrump_IdNotFound(int line, String id);

	void ErrorPrump_IdDuplicated(int line, String id);

}