#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, int> mp;
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x] = i + 1;
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		if(mp.find(x) != mp.end())
		{
			cout << mp[x] << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
