#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 20005;
int fa[MAXN], col[MAXN];
struct Edge {
	int u, v, w;
};
//二分+二分图判定+带权并查集
int N, M;
vector<Edge> edges;

int find(int x) {
	if (fa[x] != x) {
		int tmp = fa[x];
		fa[x] = find(fa[x]);
		col[x] ^= col[tmp]; //颜色差异，每一条边两个端点颜色不同
	}
	return fa[x];
}

bool check(int x) {
	for (int i = 1; i <= N; i++) {
		fa[i] = i;
		col[i] = 0;
	}
	for (const auto& e : edges) {
		if (e.w > x) {
			int u = e.u, v = e.v;
			int fu = find(u), fv = find(v);
			if (fu == fv) {
				if (col[u] == col[v]) return false;  //如果不能分开说明当前值太大
			}
			else {
				fa[fu] = fv;
				col[fu] = col[u] ^ col[v] ^ 1; //a^b^c=1,a=b^c^1。
			}
		}
	}
	return true;
}




int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}
	int l = 0, r = 1e9, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1; //二分
	}
	if(ans == 0&&check(0)) {
		cout << "0\n";
	} else {
		cout << ans << endl;
	}
	return 0;
}