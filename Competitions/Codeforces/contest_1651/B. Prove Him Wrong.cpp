/*
2022-03-10 17:48:57
https://codeforces.com/contest/1651/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const long long MAX = 1e9;
 
int cas, con=1, n;
long long s[100];
 
int main(){
 
    s[1] = 1;
    while (s[con] * 3ll <= MAX){
           s[con+1] = s[con] * 3ll;
           con++;
    }
 
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
           if (n > con) printf ("NO\n");
           else{
             printf ("YES\n%lld", s[1]);
             for (int i = 2; i <= n; ++i) printf (" %lld", s[i]);
             printf ("\n");
           }
    }
 
    return 0;
}