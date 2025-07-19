#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100005;
int a, b, p;
int fa[N];
bool is_prime[N];//素数筛
int find(int x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		fa[fx] = fy;
	}
}

void get_primes(int n)
{
	fill(is_prime, is_prime + n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (is_prime[i]) {
			for(int j = i*i;j<=n;j+=i)
				{
				is_prime[j] = false;
			}//比 i*i小的数已经被处理过了
		}
	}
}

int main()
{
	cin >> a >> b >> p;
	get_primes(b-a);
	for(int i = 0; i <= b-a; i++) {
		fa[i] = i;
	}
	for (int q = p; q <= b - a; ++q) // 遍历所有大于等于p的数,最大质因数不可能超过区间
	{
		if (!is_prime[q]) continue;
		int first = ((a + q - 1) / q) * q; //第一个大于等于a的q的倍数
		for (int x = first; x <= b; x += q) { // 遍历所有大于等于a且小于等于b的q的倍数
			Union(first - a, x - a);
		}
	}
	int cnt = 0;
	for(int i = 0; i <= b - a; i++) {
		if (fa[i] == i) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
