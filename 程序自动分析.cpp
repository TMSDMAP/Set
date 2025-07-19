#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
//并查集+离散化处理
using namespace std;
const int MAXN = 1e6 + 5;
long long fa[MAXN];
long long n, t;
long long find(long long x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void merge(long long x, long long y)
{
	long long fx = find(x);
	long long fy = find(y);
	if (fx != fy) {
		fa[fx] = fy;
	}
}

struct Node {
	long long i, j, e;
};

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<Node> eqs, neqs;
		vector<long long> all; //离散化
		long long i, j, e;
		bool flag = true;
		for (int k = 1; k <= n; k++)
		{
			cin >> i >> j >> e;
			all.push_back(i);
			all.push_back(j);
			if (e == 1)
				eqs.push_back({ i, j, e });
			else
			{
				neqs.push_back({ i, j, e });
			}
		}
		sort(all.begin(), all.end()); //排序
		all.erase(unique(all.begin(), all.end()), all.end()); //去重
		map<long long, int> id;  //离散化映射
		for (int i = 0; i < all.size(); i++)
			id[all[i]] = i + 1;  //从1开始编号
		int N = all.size();  //离散化后元素个数
		for(int i = 1; i <= N; i++) {
			fa[i] = i;
		}
		for(auto &c:eqs) {
			merge(id[c.i], id[c.j]);
		}
		for (auto& c : neqs) {
			if (find(id[c.i]) == find(id[c.j]))
			{
			flag = false;
			break;
			}
		}
		cout << (flag ? "YES" : "NO") << endl;

	}
}