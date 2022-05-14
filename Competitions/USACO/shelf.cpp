/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
** Estante\shelf\USACO\2007\      **
** diciembre\bronce\Greedy        **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 20001

using namespace std;

struct s{
      int c;
      bool operator <(const  s &R)
      const{
            return R.c < c;
      }    
}A[RAN];

long long n, T, sol, tot;

int main (){
    
    freopen("shelf.in","r",stdin);
    freopen("shelf.out","w",stdout);   	
    
    scanf ("%d %d", &n, &T);

    for (int i = 1; i <= n; i++){
         scanf ("%I64d\n",  &A[i].c);    
    }
    
    sort (A + 1, A + n + 1);
    
    for (int i = 1; i <= n && tot < T; i++){
         tot += A[i].c;
         sol = i;
    }
    
    printf ("%I64d\n",sol);
     
    return 0; 
    }
