/*
https://codeforces.com/contest/1672/problem/C
2022-04-23 17:38:20
*/
#include <bits/stdc++.h>

using namespace std;

const int RAN = 2e5 + 5;
int cas, n;
int a[RAN];

int main(){
    
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
           
           for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
           
           int l = -1;
           for (int i = 2; i <= n && l == -1; ++i)
               if (a[i] == a[i-1]) l = i-1;
               
               
           int r = -1;
           for (int i = n; i >= 1 && r == -1; --i)
               if (a[i] == a[i-1]) r = i;
           
           
           if (l == -1){
            printf ("0\n");    
           }
           else{
               int d = r - l + 1;
               if (d == 2){
                  printf ("0\n");
               }
               else{
                   
                   if (d == 3) printf ("1\n");
                   else printf ("%d\n", d-3);
               }
               
           }
    }

    return 0;
}
