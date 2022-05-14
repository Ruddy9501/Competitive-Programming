/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
** Estante2\shelf2\USACO\2007\    **
** diciembre\bronce\Combinatoria  **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 10000000

using namespace std;

long long sol, n, T, x, c,t, S[RAN];

int main (){
    
    freopen("shelf2.in","r",stdin);
    freopen("shelf2.out","w",stdout);   	
    
    scanf ("%I64d %I64d\n", &n, &T);
    sol = 999999999;
    for (int i = 1; i <= n; i++){
         scanf ("%d\n", &x);
         S[++c] = x;
         for (int j = 1; j <= t; j++){
              S[++c] = S[j] + x; 
              if (S[c] >= T && S[c] < sol)
                  sol =  S[c];
         }
         t = c;
    }
    
    printf ("%I64d\n",c);
    
    return 0; 
    }
