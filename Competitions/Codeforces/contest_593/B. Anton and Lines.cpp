/*
2015-11-04 21:07:20
https://codeforces.com/contest/593/problem/B
*/

#include <cstdio>
#include <algorithm>
 
using namespace std;
int n, con;
long long x1, x2, a, b;
struct par{
       long long ini, fin;
       bool operator <(const par &R)const{
            if (ini != R.ini)return ini < R.ini;
             else return fin < R.fin;
       }
}A[1000000];
 
int main(){
 
    scanf ("%d", &n);
    scanf ("%I64d %I64d", &x1, &x2);
    for (int i = 1; i <= n; i++){
         scanf ("%I64d %I64d", &a, &b);
         A[++con].ini = a*x1+b;
         A[con].fin = a*x2+b;
    }
 
    sort (A+1,A+n+1);
 
    bool mar = true;
    for (int i = 1; i < n; i++){
         if (A[i].ini < A[i+1].ini && A[i].fin > A[i+1].fin) mar = false;
         if (A[i].ini > A[i+1].ini && A[i].fin < A[i+1].fin) mar = false;
    }
 
    if (mar) printf ("NO\n");
    else printf ("YES\n");
 
    return 0;
}