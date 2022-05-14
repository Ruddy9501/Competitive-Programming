/*
2016-12-06 20:20:19
https://codeforces.com/contest/742/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, A[1000005], a;
 
int main(){
 
    scanf ("%d%d", &n, &m);
    int lm = 0;
    if (m != 0) 
        lm = log2(m); 
    long long sol = 0;
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         int la = log2(a);
         int b = 0;
         for (int i = 0; i <= max(la, lm); i++){
              bool ba = a&(1<<i);
              bool bm = m&(1<<i);
              if (ba^bm)  b += 1<<i;
         }
         sol += A[b];
         A[a]++;
    }
 
    printf ("%lld\n", sol);
 
    return 0;
}