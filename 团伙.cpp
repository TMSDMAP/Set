#include <iostream>
using namespace std;
const int MAXN = 10005;
int n, m;
int fa[MAXN];
int enemy[MAXN];
int find(int x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void unionSet(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		fa[fx] = fy;
	}
}
void setEnemy(int x, int y)
{
	if (enemy[x] == 0) enemy[x] = find(y); // 如果x的敌人不存在，则将y设置为x的敌人
	else unionSet(y, enemy[x]);  // 如果x的敌人已经存在，则将y与x的敌人合并
	if (enemy[y] == 0) enemy[y] = find(x);// 如果y的敌人不存在，则将x设置为y的敌人
	else unionSet(x, enemy[y]);  // 如果y的敌人已经存在，则将x与y的敌人合并
}


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		enemy[i] = 0;
	for(int i = 1; i <= n; i++) {
		fa[i] = i; // 初始化每个节点的父节点为自己
	}
	for (int i = 0; i < m; i++)
	{
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'F')
		{
			unionSet(x, y);
		}
		else if (op == 'E')
		{
			setEnemy(x, y);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (find(i) == i) count++;
	}
	cout << count << endl;
	return 0;
}
//另一种做法
/*
#include <iostream>
using namespace std;

const int MAXN = 10005;
int fa[MAXN * 2];  // 开两倍空间，x表示朋友，x+n表示敌人

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void unionSet(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fx] = fy;
}

int main() {
	int n, m;
	cin >> n >> m;
	// 初始化并查集，每个节点的父节点是自己
	for (int i = 1; i <= 2 * n; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < m; i++) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'F') {
			// 朋友关系：直接合并x和y
			unionSet(x, y);
		} else if (op == 'E') {
			// 敌人关系：x的敌人是y，y的敌人是x
			// 合并x与y的敌人集合，合并y与x的敌人集合
			unionSet(x, y + n);
			unionSet(y, x + n);
		}
	}
	// 统计1~n中不同根节点的数量
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) count++;
	}
	cout << count << endl;
	return 0;
}

*/