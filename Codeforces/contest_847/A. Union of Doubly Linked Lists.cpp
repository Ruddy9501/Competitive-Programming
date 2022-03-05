/*
2017-09-22 18:33:15
https://codeforces.com/contest/847/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, k, a[105], l[105], r[105], x[105], y[105];
 
void dfs(int u) {
	if(u == 0)
		return;
 
	a[++k] = u;
	dfs(r[u]);
}
 
int main() {
	scanf("%d", &n);
 
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);
	}
 
	for(int i = 1; i <= n; i++)
		if(l[i] == 0)
			dfs(i);
 
	for(int i = 1; i <= n; i++) {
		x[a[i]] = a[i - 1];
		y[a[i]] = a[i + 1];
	}
 
	for(int i = 1; i <= n; i++)
		printf("%d %d\n", x[i], y[i]);
 
	return 0;
}