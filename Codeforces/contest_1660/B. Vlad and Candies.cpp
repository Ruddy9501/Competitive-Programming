/*
https://codeforces.com/contest/1660/problem/B
2022-03-31 17:50:01
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e5 + 5;
int n, cas, a[RAN];
 
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        
           scanf ("%d", &n);
           for (int i = 1; i <= n; ++i) scanf ("%d\n", &a[i]);
           
           sort (a+1, a+n+1);
           
           if (n == 1){
               if (a[1] == 1) printf ("YES\n");
               else
               printf ("NO\n");
               continue;
           }
           
           if (a[n]-a[n-1] <= 1) printf ("YES\n");
           else printf ("NO\n");
    }
    
 
    return 0;
}