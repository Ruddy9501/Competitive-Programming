/*
2017-10-24 23:04:41
https://codeforces.com/contest/883/problem/I
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int64;
const int MAX = 5e5 + 5;
int n, k, tree[MAX];
int64 a[MAX];
 
void upd(int x) {
	for(; x <= n; x += x & -x)
		tree[x]++;
}
 
int query(int x) {
	if(x == 0)
		return 1;
 
	if(x < 0)
		return 0;
 
	int s = 1;
 
	for(; x > 0; x -= x & -x)
		s += tree[x];
 
	return s;
}
 
int f(int64 x) {
	for(int i = 1; i <= n; i++)
		tree[i] = 0;
 
	for(int i = k; i <= n; i++) {
		int p1 = lower_bound(a + 1, a + n + 1, a[i] - x) - a - 1;
		int p2 = i - k;
 
		//printf("%d : %d %d\n", i, p1, p2);
 
		if(p1 <= p2) {
			int q = query(p2) - query(p1 - 1);
 
			if(q > 0)
				upd(i);
		}
	}
 
	return query(n) - query(n - 1);
}
 
int main() {
	scanf("%d%d", &n, &k);
 
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
 
	sort(a + 1, a + n + 1);
	//printf("%d\n", f(20));
 
	int64 st = 0, nd = INT_MAX, ans = INT_MAX;
 
	while(st <= nd) {
		int64 mid = (st + nd) / 2LL;
 
		if(f(mid)) {
			ans = min(ans, mid);
			nd = mid - 1;
		}
 
		else st = mid + 1;
	}
 
	printf("%lld\n", ans);
	return 0;
}