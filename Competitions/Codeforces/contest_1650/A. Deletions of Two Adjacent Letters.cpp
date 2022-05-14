/*
2022-03-09 23:30:35
https://codeforces.com/contest/1650/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
int cas, la, lb;
char a[100], b[100];
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%s", a);
           scanf ("%s", b);
 
           la = strlen (a);
           lb = strlen (b);
 
           bool flag = false;
           for (int i = 0; i < la; ++i)
                if (a[i] == b[0] and i % 2 == 0)
                    flag = true;
 
           if (flag) printf ("YES\n");
           else printf ("NO\n");
 
    }
 
 
    return 0;
}