/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
** USACO\2007-2008\abril          ** 
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 105
#define MAX 10005

using namespace std;

int sol, n, m;
int M[RAN][RAN], A[MAX];

int main (){
    
    freopen("danger.in","r",stdin);
    freopen("danger.out","w",stdout);   	
    
    scanf ("%d %d\n", &n ,&m);
    
    for (int i = 1; i <= m; i++)
         scanf ("%d\n",&A[i]);
    
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
              scanf ("%d", &M[i][j]);
    
    for (int k = 1; k <= n; k++)
         for (int i = 1; i <= n; i++)
              for (int j = 1; j <= n; j++)
                   M[i][j] <?= min (M[i][j], M[i][k] + M[k][j]);
    
    for (int i = 1; i < m; i++)
         sol += M[A[i]][A[i+1]];
    
    printf ("%d\n", sol);
    
    return 0; 
    }
