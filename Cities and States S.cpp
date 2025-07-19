#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<string, int> cnt;
	vector<pair<string, string>> cities(n);
	for (int i = 0; i < n; i++)
	{
		string city, state;
		cin >> city >> state;
		cities[i] = { city, state };
		string key = city.substr(0, 2) + state; //前两个字母+州代码
		cnt[key]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string city = cities[i].first;
		string state = cities[i].second;
		string key2 = state + city.substr(0, 2);
		if (city.substr(0, 2) != state) {
			ans += cnt[key2];
		}
	}
	cout << ans / 2 << endl;
	return 0;

}