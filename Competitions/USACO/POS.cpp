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

#define RAN 1000
#define oo 1 << 29

using namespace std;

int nod, newn, I, nc, nd, x, y;
int C[RAN];
bool M[RAN][RAN];
queue <int> Q;
vector <int> V[RAN];

struct tres{
            int nod, newn;
            bool mar;
            tres (int a = 0, int b = 0){
                  nod = a;
                  newn = b;
                  mar = false;
            }
           int bus (int x){
                    if (x == nod)
                        return newn;
                     else
                        return nod;       
           }       
}A[RAN];

void camino(int nod){
            for (int i = 0; i < V[nod].size(); i++){
                 int I = V[nod][i];
                 if (!A[I].mar && x != y){
                     A[I].mar = true;
                     newn = A[I].bus(nod);
                     camino(newn);
                 } 
            }
          Q.push(nod); 
}

int main (){
    
    freopen("POS.in","r",stdin);
    freopen("POS.out","w",stdout);  
    
    scanf ("%d %d\n", &nd, &nc);
    
    for (int i = 1; i <= nd; i++)
         scanf ("%d\n", &C[i]); 
    
    for (int i = 1; i <= nc; i++){
         scanf("%d %d\n", &x, &y);
             M[x][y] = true;
             V[x].push_back(i);
             V[y].push_back(i);
             A[i] = tres (x, y);
    } 	
    
    camino(1);
    
    printf ("%d\n",Q.size() - 1);
    printf ("%d",Q.front());
    Q.pop();
    while (!Q.empty()){
           printf (" %d",Q.front());
           Q.pop();    
    }
    
    return 0; 
    }
