/*
https://codeforces.com/contest/1660/problem/E
2022-03-31 19:22:05
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e3 + 5;
int n, cas;
char a[RAN][RAN];
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        
           scanf ("%d", &n);
         
           for (int i = 0; i < n; ++i) scanf ("%s", a[i]);
           
           
           int con = 0;
           for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (a[i][j] == '1') con++;
                    
           int ma = 0;         
           for (int i = 0; i < n; ++i){
               int r = 0, p = i;
               int r1 = 0, p1 = i;
               for (int j = 0; j < n; ++j){
                    r += (a[j][p] == '1');
                    r1 += (a[p][j] == '1');
                    p = (p + 1) % n;
                    p1 = (p1 + 1) % n;
               }
               
               ma = max (ma, r);
               ma = max (ma, r1);
           }     
           
           printf ("%d\n", con - ma + (n - ma));
    }
    
 
    return 0;
}