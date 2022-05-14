/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
**USACO\2011-2012\marzo           **
************************************
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 1001
#define oo 1 << 29

using namespace std;

struct tres{
       int f, c, cos;
       tres (int a = 0, int b = 0,int d = 0){
             f = a;
             c = b;
             cos = d;
       }
};
 
int X, Y, n, f, c, nf, nc, x, y, cos;
bool M[RAN][RAN], M1[RAN][RAN];
queue <tres>Q, Q1;
const int mf[4] = { 0, 0, 1,-1},
          mc[4] = {-1, 1, 0, 0};
int main (){
    
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);   	
    
    scanf ("%d %d %d\n", &n, &X, &Y);
    
    for (int i = 1; i <= n; i++){
         scanf ("%d %d\n", &x, &y);
         M[x][y] = true;
    }
    
    Q.push(tres(X, Y, 0));
    while (!Q.empty() || !Q1.empty()){
    while (!Q.empty()){
           f = Q.front().f;
           c = Q.front().c;
           cos = Q.front().cos;
           Q.pop();
           for (int i = 0; i < 4; i++){
                nf = mf[i] + f;
                nc = mc[i] + c;
                if (nc <= 1){
                    printf("%d\n",cos);
                    return 0;
                }
                if (nf <= RAN && nf >= 0 && nc <= RAN  && nc >= 0 && !M1[nf][nc]){
                    M1[nf][nc] = true;
                    if (M[nf][nc] == false){
                        Q.push(tres(nf, nc, cos));
                    }
                     else
                        Q1.push(tres(nf, nc, cos+1));
                }
           }
    }
           
    while (!Q1.empty()){
           f = Q1.front().f;
           c = Q1.front().c;
           cos = Q1.front().cos;
           Q1.pop();
           for (int i = 0; i < 4; i++){
                nf = mf[i] + f;
                nc = mc[i] + c;
                if (nc <= 1){
                    printf("%d\n",cos);
                    return 0;
                }
                if (nf <= RAN  && nf >= 0 && nc <= RAN  && nc >= 0 && !M1[nf][nc]){
                    M1[nf][nc] = true;   
                    if (!M[nf][nc]){
                        Q1.push(tres(nf, nc, cos));
                    }
                     else
                        Q.push(tres(nf, nc, cos + 1));
                }
           }
    }
    }
     
    return 0; 
    }
