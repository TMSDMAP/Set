#include <iostream>
#include <set>
using namespace std;
int m;
set<long long> lumber;
int main()
{
	cin >> m;
	while (m--) {
		int op;
		long long len;
		cin >> op >> len;
		if (op == 1) {
			if (lumber.count(len))
				cout << "Already Exist" << endl;
			else lumber.insert(len);
		}
		else if (op == 2)
		{
			if (lumber.empty())
				cout << "Empty" << endl;
			else
			{
				if (lumber.count(len))
				{
					cout << len << endl;
					lumber.erase(len);
				}
				else
				{
					auto lb = lumber.lower_bound(len);
					if (lb == lumber.begin()) {
						cout << *lb << endl;
						lumber.erase(lb);
					}
					else if (lb == lumber.end()) {
						auto pre = prev(lb);
						cout << *pre << endl;
						lumber.erase(pre);
					}
					else
					{
						auto pre = prev(lb);
						if (abs(*lb - len) < abs(*pre - len)) {
							cout << *lb << endl;
							lumber.erase(lb);
						}
						else
						{
						cout << *pre << endl;
						lumber.erase(pre);
						}
					}
				}
			}
		}
	}
	return 0;
}