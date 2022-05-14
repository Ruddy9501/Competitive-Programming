/*
https://codeforces.com/contest/1669/problem/B
2022-04-22 13:08:03
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e5 + 5;
int n, m;
int c[RAN], a[RAN];
 
int main(){
    
    scanf ("%d", &n);
    while (n--){
           scanf ("%d", &m);
           for (int i = 1; i <= m; ++i){
               scanf ("%d", &a[i]);
               c[a[i]]++;
           } 
           
           int sol = -1;
           for (int i = 1; i <= m; ++i){
                if (c[a[i]] >= 3){
                    sol = a[i];
                }
                c[a[i]] = 0;
           }
           
           printf ("%d\n", sol);
    }
    
    return 0;
}
