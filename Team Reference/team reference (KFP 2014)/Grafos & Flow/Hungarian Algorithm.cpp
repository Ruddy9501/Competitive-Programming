# include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1000 * 1000 * 1000;

int n;
int a[MAXN][MAXN];
int u[MAXN], v[MAXN], link[MAXN], par[MAXN], used[MAXN], minval[MAXN];

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAXN; j++) {
			used[j] = false;
			minval[j] = INF;
		}
		
		int j_cur = 0;
		par[j_cur] = i;
		
		do {
			used[j_cur] = true;
			int j_next, delta = INF, i_cur = par[j_cur];
			
			for (int j = 0; j <= n; j++)
				if (!used[j]) {
				    int cur = a[i_cur][j] - u[i_cur] - v[j];
					if (cur < minval[j]) {
						 minval[j] = cur; link[j] = j_cur;
					}
					if (minval[j] < delta) {
					 delta = minval[j]; j_next = j;
					}
				}
			
			for (int j = 0; j <= n; j++)
				if (used[j]) {
					 u[par[j]] += delta; v[j] -= delta;
				}
				else {
					minval[j] -= delta;
				}
				j_cur = j_next;
		} while (par[j_cur]);
		
		do {
			int j_prev = link[j_cur];
			par[j_cur] = par[j_prev];
			j_cur = j_prev;
		} while (j_cur > 0);
	}

	printf("%d", -v[0]);
	return 0;
}
