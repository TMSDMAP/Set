#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int N;
unordered_map<string, int> mp;
int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		mp[s]++;
	}
	int t = mp.size();
	cout << t << endl;
	return 0;
}