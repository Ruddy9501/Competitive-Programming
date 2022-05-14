/*
2017-09-22 21:47:18
https://codeforces.com/contest/847/problem/K
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, a, b, k, f, l, cost[1005][1005], e[1000005];
char x[25], y[25];
map <string, int> id;
 
int main() {
	scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
 
	int last = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%s%s", x, y);
 
		string O = x;
 
		if(!id.count(O))
			id[O] = ++l;
 
		string P = y;
 
		if(!id.count(P))
			id[P] = ++l;
 
		int q = id[O], w = id[P];
 
		if(last == q)
			cost[q][w] += b;
 
		else cost[q][w] += a;
 
		last = w;
 
		//printf("%d %d %d\n", q, w, cost[q][w]);
	}
 
	long long sol = 0;
 
	int c = 0;
	for(int i = 1; i <= l; i++) {
		for(int j = i + 1; j <= l; j++) {
			e[++c] = cost[i][j] + cost[j][i];
			sol += e[c];
		}
	}
 
	sort(e+ 1, e + c + 1);
 
	for(int i = c; i > 0; i--) {
		if(k > 0 && f < e[i]) {
			sol -= e[i];
			sol += f;
			k--;
		}
	}
 
	printf("%lld\n", sol);
	return 0;
}