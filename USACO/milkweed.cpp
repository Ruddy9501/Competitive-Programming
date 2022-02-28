/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 105
#define oo 1 << 29

using namespace std;
typedef pair<int, int>par;

const int mf[9] = {0, 0, 1,-1, 1,-1, 1,-1}, 
          mc[9] = {1,-1, 0, 0, 1, 1,-1,-1};

int sol, nf, nc, f, c, n, m, F, C, X, Y;
char M[RAN][RAN], A[RAN];
bool mar;
queue <par>Q, Q1;

int main (){
    
    freopen ("milkweed.in","r",stdin);
    freopen ("milkweed.out","w",stdout);   	

    scanf ("%d %d %d %d\n", &F, &C, &X, &Y); 
    
    for (int i = 1; i <= C; i++){
         scanf("%s",A);
         for(int j = 0; j < F; j++)
             M[i][j+1] = A[j];
    } 
     
    Q1.push(par(C-Y+1, X));
    M[C-Y+1][X] = '*';
    while (!Q.empty() || !Q1.empty()){
          mar = false;
           while (!Q1.empty()){
                 c = Q1.front().first;
                 f = Q1.front().second;
                 Q1.pop();
                 for (int i = 0; i < 8; i++){
                      nf = mf[i] + f;
                      nc = mc[i] + c;
                      if(M[nc][nf] == '.'){
                         M[nc][nf] = 'm';
                         Q.push(par(nc, nf));
                         if (!mar){
                             sol++;
                             mar = true;
                         } 
                      }
                 } 
           }
           mar = false;
           while (!Q.empty()){
                  c = Q.front().first;
                  f = Q.front().second;
                  Q.pop();
                  for (int i = 0; i < 8; i++){
                       nf = mf[i] + f;
                       nc = mc[i] + c;
                       if (M[nc][nf] == '.'){
                           M[nc][nf] = 'M';
                           Q1.push(par(nc, nf));
                           if (!mar){
                               sol++;
                               mar = true; 
                           }
                       } 
                  }
           }
    } 
     
    printf("%d\n",sol);
    
    return 0; 
    }
