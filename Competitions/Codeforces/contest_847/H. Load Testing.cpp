/*
2017-09-22 19:48:35
https://codeforces.com/contest/847/problem/H
*/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int64;
const int MAX = 1e5 + 5;
int n, a[MAX];
int64 l[MAX], r[MAX], numL[MAX], numR[MAX];
 
int main() {
	scanf("%d", &n);
 
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
 
	for(int i = 1; i <= n; i++) {
		l[i] = l[i - 1];
		numL[i] = a[i];
 
		if(numL[i] <= numL[i - 1]) {
			l[i] += numL[i - 1] - numL[i] + 1;
			numL[i] = numL[i - 1] + 1;
		}
	}
 
	for(int i = n; i > 0; i--) {
		r[i] = r[i + 1];
		numR[i] = a[i];
 
		if(numR[i] <= numR[i + 1]) {
			r[i] += numR[i + 1] - numR[i] + 1;
			numR[i] = numR[i + 1] + 1;
		}
	}
 
	int64 sol = 1e18;
	for(int i = 1; i <= n; i++) {
		int64 op = l[i - 1] + r[i + 1];
		int64 mx = max(numL[i - 1], numR[i + 1]);
 
		if(a[i] <= mx)
			op += mx - a[i] + 1;
 
		sol = min(sol, op);
	}
 
	printf("%lld\n", sol);
	return 0;
}