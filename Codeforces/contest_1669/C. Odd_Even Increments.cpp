/*
https://codeforces.com/contest/1669/problem/C
2022-04-22 13:08:25
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
           for (int i = 0; i < m; ++i){
               scanf ("%d", &a[i]);
           } 
           
           bool flag = true;
           for (int i = 0; i < m; ++i){
                if(a[i%2]%2 != a[i]%2) flag = false;
           }
           if (flag)
            printf ("YES\n");
           else
            printf ("NO\n");
    }
    
    return 0;
}
