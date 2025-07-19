#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1005;
int n, m;
int fa[N];
int find(int x) {
	if(fa[x]!=x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void Union(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		fa[fx] = fy;
}

int main() {
	while (1)
	{
		cin >> n;
		if (n == 0) return 0;
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			Union(x, y);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (fa[i] == i)
				cnt++;
		}
		cout << cnt - 1 << endl;
	}
}