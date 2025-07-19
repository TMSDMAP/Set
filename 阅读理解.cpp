#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int N;
unordered_map<string, vector<int>> mp;
int M;
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int L;
		cin >> L;
		//set<string> appeared;
		for(int j = 0; j < L; ++j)
		{
			string s;
			cin >> s;
			/*
			if(appeared.count(s)) continue;
			appeared.insert(s);
			mp[s].push_back(i+1);
			*/
			bool found = false;
			for (auto k : mp[s])
				if (k == i+1)
				{
				found = true;
				break;
				}
			if (!found)
			mp[s].push_back(i+1);
		}
	}
	cin >> M;
	while (M--)
	{
		string s1;
		cin >> s1;
		if (mp.find(s1) == mp.end())
		{
			cout << endl;
			continue;
		}
		vector<int>& v = mp[s1];
		for (int i = 0;i<v.size();i++)
		{
			if (i) cout << " ";
			cout <<v[i];
		}
		cout << endl;
	}
	return 0;
}