/*
2017-09-05 19:27:13
https://codeforces.com/contest/846/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 5*1e3+5;
int n, a, b, c;
long long  A[RAN], P[RAN];
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 scanf ("%lld", &A[i]);
    	 P[i] = P[i-1] + A[i];
    }
    
    long long S = -(1ll<<60); int id1, id2;
    for (int i = 1; i <= n; i++){
    	 long long sum1 = -(1ll<<60);
    	 for (int j = 1; j <= i; j++){
              long long s = P[j-1] - (P[i-1]-P[j-1]);
              if (s > sum1) sum1 = s, id1 = j;
         }
 
         long long sum2 = P[n] - P[i-1]; id2 = n+1;
         for (int j = i; j <= n; j++){
              long long s = (P[j-1]-P[i-1]) - (P[n]-P[j-1]);
              if (s > sum2) sum2 = s, id2 = j;
         }
        // printf ("%lld %lld\n", sum1, sum2);
         if (sum1 + sum2 > S) {
         	 S = sum1 + sum2;
         	 a = id1;
         	 b = i;
         	 c = id2;
         }
    }
   // printf ("%lld\n", S);
    printf ("%d %d %d\n", a-1, b-1, c-1); 
 
	return 0;
}