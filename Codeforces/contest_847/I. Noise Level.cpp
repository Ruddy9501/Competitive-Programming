/*
2017-09-22 21:13:53
https://codeforces.com/contest/847/problem/I
*/
#include <bits/stdc++.h>
using namespace std;
 
const int
	mf[4] = { -1, 1, 0, 0 },
	mc[4] = { 0, 0, -1, 1 };
int n, m, q, p, v[255], dist[255][255], ans[255][255];
char a[255][255];
 
void bfs(int f, int c, int d) {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dist[i][j] = -1;
 
	queue <pair <int, int> > q;
	q.push({f, c});
	dist[f][c] = 0;
 
	//printf("%d\n", d);
 
	int st = 0;
	while(d > 0) {
		v[st++] = d;
		d /= 2;
	}
 
	while(!q.empty()) {
		f = q.front().first;
		c = q.front().second;
		q.pop();
 
		//printf("%d %d : %d\n", f, c, v[dist[f][c]]);
 
		ans[f][c] += v[dist[f][c]];
 
		for(int i = 0; i < 4; i++) {
			int nf = f + mf[i];
			int nc = c + mc[i];
 
			if(nf < 1 || nf > n || nc < 1 || nc > m || a[nf][nc] == '*')
				continue;
 
			if(dist[f][c] + 1 >= st)
				continue;
 
			if(dist[nf][nc] == -1) {
				dist[nf][nc] = dist[f][c] + 1;
				q.push({nf, nc});
			}
		}
	}
}
 
int main() {
	scanf("%d%d%d%d", &n, &m, &q, &p);
 
	for(int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);
 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] >= 'A' && a[i][j] <= 'Z')
				bfs(i, j, q * (a[i][j] - 'A' + 1));
 
	/*for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}*/
 
	int sol = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(ans[i][j] > p)
				sol++;
 
	printf("%d\n", sol);
	return 0;
}