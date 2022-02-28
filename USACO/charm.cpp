/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
** Brazalete de Dijes\charm\      **
** USACO\2007\diciembre\          ** 
** plata\Mochila sin repeticion   **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 13000

using namespace std;

int sol, n, t, a, b;
int C[RAN];
bool M[RAN];

int main (){
    
    freopen ("charm.in","r",stdin);
    freopen ("charm.out","w",stdout);   	
    
    scanf ("%d %d\n", &n, &t);
    
    M[0] = true;
    for (int i = 1; i <= n; i++){
         scanf ("%d %d\n", &a, &b);
         for (int j = t-a;j >= 0; j--){
              if (M[j] == true && C[j+a] < C[j]+b){
                  C[j+a] = C[j] + b;
                  M[j+a] = true;
                  sol >?= C[j+a]; 
              }
         }
    }
    
    printf ("%d\n",sol);
    
    return 0; 
    }
