/*
2017-07-26 22:24:55
https://codeforces.com/contest/286/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
 
const int P = 21;
const int MAX = 1 << (P + 1); //mayor q 2 * (tamanno polinomio)
const int GEN = 3;
const int MOD = 23068673;
 
int N;
int w[MAX];
 
int exp(int a, int b) {
	if(b == 0)
		return 1;
 
	if(b % 2 == 1)
		return 1LL * a * exp(a, b - 1) % MOD;
 
	int sq = exp(a, b / 2);
	return 1LL * sq * sq % MOD;
}
 
void NTT(int a[], int x[], int k, int v) {
	//K is the length of x[]
  	//v=0 : DFT,  v=1 : IDFT
 
	w[0] = 1;
 
	int G = exp(GEN, (MOD - 1) / k);
 
	for(int i = 1; i <= k; i++)
		w[i] = 1LL * w[i - 1] * G % MOD;
 
	for(int i = 0, j = 0; i < k; i++) {
		if(i > j)
			swap(x[i], x[j]);
 
		for(int l = k >> 1; (j ^= l) < l; l >>= 1);
	}
 
	for(int i = 2; i <= k; i <<= 1) {
		int mid = i >> 1;
 
		for(int j = 0; j < k; j += i) {
			for(int l = 0; l < mid; l++) {
				int t;
 
				if(v == 0)
					t = 1LL * x[j + l + mid] * w[(k / i) * l] % MOD;
 
				else t = 1LL * x[j + l + mid] * w[k - (k / i) * l] % MOD;
 
				x[j + l + mid] = (x[j + l] - t + MOD) % MOD;
				x[j + l] += t;
				x[j + l] %= MOD;
			}
		}
	}
 
	if(v == 1) {
		int r = exp(N, MOD - 2);
 
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * r % MOD;
	}
}
 
//0-indexed
void calculate(int la, int a[], int lb, int b[]) {
	N = 1;
 
	while(N <= la + lb)
		N *= 2;
 
	for(int i = la; i < N; i++)
		a[i] = 0;
 
	for(int i = lb; i < N; i++)
		b[i] = 0;
 
	NTT(a, a, N, 0); NTT(a, b, N, 0);
    for(int i = 0; i < N; i++)
		a[i] = 1LL * a[i] * b[i] % MOD;
 
	NTT(a, a, N, 1);
}
 
int n, k, mx = 1e6+1;
int x[MAX], y[MAX], z[MAX];
 
 
int m, a;
 
bool M[MAX], mm[MAX];
 
int main() {
 
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         M[a] = true;
         x[a] = 1;
         y[a] = 1;
	}
 
	x[0] = 1;
	y[0] = 1;
 
	calculate (m+1, y, m+1, x);
 
 
	vector <int> v;
	for (int i = 1; i <= m; i++){
         //printf ("%d %d\n", i, y[i]);
         if (y[i] > 0){
             if (!M[i]){
                 printf ("NO\n");
                 return 0;
             }
             if (y[i] == 2)
                 v.push_back(i);
         }
	}
 
	printf ("YES\n%d\n", (int)v.size());
	printf ("%d", v[0]);
	for (int i = 1; i < (int)v.size(); i++){
         printf (" %d", v[i]);
	} printf ("\n");
 
	return 0;
}