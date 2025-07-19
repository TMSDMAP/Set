#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5005;
int fa[N];
int n, m, p;
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

void Union(int x, int y)
{
	if(find(x) != find(y))
		fa[find(x)] = find(y);
}

int main()
{
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}
	for (int i = 0; i < p; i++)
	{
		int x, y;
		cin >> x >> y;
		if (find(x) == find(y))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}