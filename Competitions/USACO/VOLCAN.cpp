/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 1100

using namespace std;
typedef pair<int, int>par;

 
int nf, nc, f, c, F, C, X, Y;
int A[RAN][RAN];
char M[RAN][RAN];
queue <par>Q;
const int mf[8] = {0, 0, 1,-1, 1, 1,-1,-1},
          mc[8] = {1,-1, 0, 0, 1,-1,-1, 1}; 
          
int main (){
    
    freopen("VOLCAN.in","r",stdin);
    freopen("VOLCAN.out","w",stdout);   	

    scanf ("%d %d\n", &F, &C);
    scanf ("%d %d\n", &X, &Y);
    
    for (int i = 1; i <= C; i++){
         for (int j = 1; j <= F; j++)
              scanf ("%d", &A[i][j]);
    }
    
    Q.push(par(Y, X));
    M[Y][X] = 'X';
    while (!Q.empty()){
           f = Q.front().second;
           c = Q.front().first;
           Q.pop();
           for (int i = 0; i < 8; i++){
                nf = mf[i] + f;
                nc = mc[i] + c;
                if (M[nc][nf] != 'X' && A[c][f] > A[nc][nf] && nc <= C && nf <= F && nc >= 1 && nf >= 1){
                    M[nc][nf] = 'X';
                    Q.push(par(nc, nf));
                }
           }
    }
       
    for (int i = 1; i <= C; i++){
         for (int j = 1; j <= F; j++){
              if (M[i][j] == 'X')
                  printf ("%c",M[i][j]);
               else
                  printf ("%d",A[i][j]);
              if(j == F)
                 printf("\n");
               else
                 printf(" ");  
         }
    }
 
    return 0; 
    }
