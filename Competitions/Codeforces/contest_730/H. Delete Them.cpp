/*
2016-11-03 16:26:17
https://codeforces.com/contest/730/problem/H
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, m, d[105], l[105], del[105];
char a[105][105], p[105];
 
bool match(int id) {
	int l1 = strlen(a[id] + 1);
	int l2 = strlen(p + 1);
 
	if(l1 != l2)
		return 0;
 
	for(int i = 1; i <= l1; i++) {
		if(p[i] == '?')
			continue;
 
		if(p[i] != a[id][i])
			return 0;
	}
 
	return 1;
}
 
int main() {
	scanf("%d%d", &n, &m);
 
	for(int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
		l[i] = strlen(a[i] + 1);
	}
 
	int mx = 0, mn = 1e9;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &d[i]);
 
		del[d[i]] = 1;
 
		mx = max(mx, l[d[i]]);
		mn = min(mn, l[d[i]]);
	}
 
	if(mx != mn) {
		printf("No\n");
		return 0;
	}
 
	for(int i = 1; i <= mx; i++) {
		set <char> s;
		for(int j = 1; j <= m; j++) {
			int id = d[j];
			s.insert(a[id][i]);
		}
 
		if((int) s.size() == 1)
			p[i] = *s.begin();
 
		else p[i] = '?';
	}
 
	for(int i = 1; i <= n; i++) {
		if(match(i) && !del[i]) {
			printf("No\n");
			return 0;
		}
	}
 
	printf("Yes\n");
	printf("%s\n", p + 1);
 
	return 0;
}