/*
2017-06-27 17:43:10
https://codeforces.com/contest/820/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
 
    int c, v0, v1, a, l;
    scanf ("%d%d%d%d%d", &c, &v0, &v1, &a, &l );
 
    int con = 0;
    while (1){
           c = c - min(v0+con*a, v1);
           if (c < 1) break;
           c += l;
           con++;
    }
 
    printf ("%d\n", con+1);
 
    return 0;
}