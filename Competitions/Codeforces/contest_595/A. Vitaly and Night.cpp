/*
2015-11-08 19:40:29
https://codeforces.com/contest/595/problem/A
*/
#include <cstdio>
 
using namespace std;
int n, m, sol, A[1000][1000];
int main(){
 
    scanf ("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 2*m; j++)
         scanf ("%d", &A[i][j]);
 
    for (int i = 1; i <= n; i++)
    for (int j = 2; j <= 2*m; j+=2)
         if (A[i][j] == 1 || A[i][j-1]==1) sol++;
 
    printf ("%d\n", sol);
 
    return 0;
}