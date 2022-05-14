/*
2016-04-27 18:30:20
https://codeforces.com/contest/346/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, mx, mix, x, A[100000], X[105], T, c;
bool mar;
 
int main() {
 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &X[i]);
		if (i==1)mix = X[i];
		mx = max(X[i], mx);
	}
 
    for (int i = 1; i <= n; i++)
         for (int j = i+1; j <= n; j++){
              A[++c] = __gcd(X[i],X[j]);
         }
 
    for (int i = 1; i <= c; i++)
         for (int j = i+1; i <= c; i++)
              mix = min(__gcd(A[i],A[j]), mix);
 
    T = mx/mix-n;
 
    if((T)%2 == 0)
        printf("Bob\n");
     else
        printf("Alice\n");
 
	return 0;
}