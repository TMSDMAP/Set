#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> fa;

string find(string x)
{
	if (fa.find(x) == fa.end()) return x;
	if (fa[x] == x) return x;
	return find(fa[x]); // Path compression
}


int main()
{
	string s;
	string father;
	while (cin >> s)  //不要用getline，因为getline会读取到空格和换行符
	{
		//if (s=="$") break;
		char op = s[0];
		string a = s.substr(1);
		if (op == '$') {
			 break;
		}// End of input
		if (op == '#')
		{
			father = a;
		}
		else if (op == '+')
		{
			fa[a] = father; // Set the father for a
		}
		else if (op == '?')
		{
			string fa_a = find(a);
			cout << a << " " << fa_a <<'\n'; // Output the father of a
		}
	}
	return 0;
}