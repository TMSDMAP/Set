#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int T;
int main() {
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		unordered_set<int> s;
		vector<int> ans;
		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (s.find(x) == s.end())
			{
				s.insert(x);
				ans.push_back(x);
			}
			//s.insert(x);
		}
		for(int x:ans) {
			cout << x << " ";
		}
		cout << endl;
	}
}