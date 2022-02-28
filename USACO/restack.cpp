/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
**USACO\2011-2012\marzo           **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 100001
#define oo 1 << 29

using namespace std;

long long sol, med, n, x, y;
int M[RAN];

int main (){
    
    freopen("restack.in","r",stdin);
    freopen("restack.out","w",stdout);   	

    scanf ("%I64d\n",&n);
    
    for (int i = 1; i <= n; i++){
         scanf ("%d %d\n", &x, &y);
         M[i] = M[i-1] + x - y;
    }
    
    sort(M + 1, M + n + 1);
    
    med = M[n/2];
     
    for (int i = 1; i <= n; i++){
         sol += abs(M[i] - med);
    } 
    
    printf ("%I64d\n",sol);
     
    return 0; 
    }
