/*
2016-12-06 18:26:01
https://codeforces.com/contest/742/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, A[1005], C[10005], a;
bool M[10005];
 
int bfs(int p){
    int con = 0;
    while (M[p] == false){
           con++;
           M[p] = true;
           p = A[p];
    }
    return con;
}
 
int main(){
 
    scanf ("%d", &n);
 
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         C[A[i]]++;
    }
 
    for (int i = 1; i <= n; i++){
         if (C[i] == 0){
             printf ("-1\n");
             return 0;
         }
    }
 
    int sol = 1;
    for (int i = 1; i <= n; i++){
         if (!M[i]){
             int a = bfs(i);
             if (a % 2 == 0) a/=2;
             sol = sol*a/__gcd(sol, a);
         }
    }
 
    printf ("%d\n",sol);
 
    return 0;
}