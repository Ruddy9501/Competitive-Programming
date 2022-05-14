/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
** USACO\2011-2012\febrero        **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 1005
#define oo 1 << 29

using namespace std;

int n, a, r, t, x, y, c, d;
int A[RAN], B[RAN], M[RAN][RAN];

int main (){
    
    freopen("landscape.in","r",stdin);
    freopen("landscape.out","w",stdout);   	
    
    scanf ("%d %d %d %d\n", &n, &a, &r, &t);
    
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &x, &y);
         for (int j = 1; j <= x; j++)
              A[++c] = i;
         for (int j = 1; j <= y; j++)
              B[++d] = i;   
    }
    
    for (int i = 1; i <= c; i++)
         M[i][0] = i * r;
    for (int i = 1; i <= d; i++)
         M[0][i] = i * a;
    
     
    for (int i = 1; i <= c; i++){
         for (int j = 1; j <= d; j++){
              M[i][j] = oo;
              M[i][j] <?= M[i][j-1] + a;
              M[i][j] <?= M[i-1][j] + r; 
              M[i][j] <?= M[i-1][j-1] + t * abs(A[i] - B[j]);
         }
    }
    
    printf ("%d\n",M[c][d]);
    
    return 0; 
    }
