/*
2017-10-24 22:26:08
https://codeforces.com/contest/883/problem/G
*/
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 5e5 + 5;
int n, m, s, mk[MAX], s1[MAX], s2[MAX];
 
struct data {
	int to, id, t;
 
	data(int to, int id, int t) : to(to), id(id), t(t) {}
};
 
vector <data> g[MAX];
 
void dfs1(int u) {
	mk[u] = 1;
	for(auto o : g[u]) {
		int v = o.to;
 
		if(mk[v])
			continue;
 
		if(o.t != 2)
			s1[o.id] = o.t;
 
		dfs1(v);
	}
}
 
void dfs2(int u) {
	mk[u] = 1;
 
	for(auto o : g[u]) {
		int v = o.to;
 
		if(mk[v])
			continue;
 
		if(o.t == 2)
			dfs2(v);
	}
}
 
int main() {
	scanf("%d%d%d", &n, &m, &s);
 
	for(int i = 1; i <= m; i++) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
 
		if(t == 1)
			g[a].push_back({b, i, 2});
 
		else {
			s1[i] = s2[i] = 1;
			g[a].push_back(data(b, i, 1));
			g[b].push_back(data(a, i, -1));
		}
	}
 
	dfs1(s);
 
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += mk[i];
 
	printf("%d\n", cnt);
	for(int i = 1; i <= m; i++) {
		if(s1[i] == 1)
			printf("+");
 
		else if(s1[i] == -1)
			printf("-");
	}
 
	printf("\n");
 
	for(int i = 1; i <= n; i++)
		mk[i] = 0;
 
	dfs2(s);
 
	cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += mk[i];
 
	for(int i = 1; i <= n; i++) {
		if(mk[i])
			continue;
 
		for(auto o : g[i])
			if(o.t != 2)
				s2[o.id] = o.t;
	}
 
	printf("%d\n", cnt);
	for(int i = 1; i <= m; i++) {
		if(s2[i] == 1)
			printf("+");
 
		else if(s2[i] == -1)
			printf("-");
	}
 
	printf("\n");
	return 0;
}