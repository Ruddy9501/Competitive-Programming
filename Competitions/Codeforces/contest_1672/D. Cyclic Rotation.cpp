/*
https://codeforces.com/contest/1672/problem/D
2022-04-23 18:42:42
*/
#include <bits/stdc++.h>

using namespace std;

const int RAN = 2e5 + 5;
int cas, n;
int a[RAN], b[RAN], c[RAN], ant[RAN], aux[RAN];

int main(){
    
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
           
           for (int i = 1; i <= n; ++i){
                scanf ("%d", &a[i]);
                c[a[i]]++;
           }
            for (int i = 1; i <= n; ++i)
                scanf ("%d", &b[i]);
               
           
           int pa = 1, pb = 1;
           bool flag = true;
           while (pb <= n && pa <= n){
               
                  if (a[pa] == b[pb]){
                     
                      if (ant[a[pa]] == 0) pa++, c[a[pa]]--;
                       else ant[a[pa]]--;
                      pb ++;
                  }
                  else{
                     
                      while (a[pa] != b[pb] && pa <= n){
                             c[a[pa]]--;
                             ant[a[pa]]++;
                             if (c[a[pa]] == 0) flag = false;
                             pa++;
                      }
                  }
           }
           
           if (pb > n) printf ("YES\n");
            else printf ("NO\n");
           
           for (int i = 1; i <= n; ++i) c[a[i]] = ant[a[i]] = 0;
          
    }

    return 0;
}
