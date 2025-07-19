#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, long long> Stu;

int main()
{
	int n;
	cin >> n;
	int op;
	for (int i = 0; i < n; ++i)
	{
		cin >> op;
		if (op == 1)
		{
			string s;
			cin >> s;
			long long x;
			cin >> x;
			Stu[s] = x;
			cout << "OK" << endl;
		}
		else if (op == 2)
		{
			string s;
			cin >> s;
			if(Stu.find(s) != Stu.end())
			{
				cout << Stu[s] << endl;
			}
			else
			{
				cout << "Not found" << endl;
			}
		}
		else if (op == 3)
		{
			string s;
			cin >> s;
			if (Stu.find(s) != Stu.end())
			{
				Stu.erase(s);
				cout << "Deleted successfully" << endl;
			}
			else cout << "Not found" << endl;
		}
		else if(op==4)
			cout << Stu.size() << endl;
	}
	return 0;
}

