/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/

#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 1000
#define oo 1 << 29

using namespace std;
typedef pair<int,int>par;

int sol, nod, newn, dir, d, n, i, j, F[RAN], C[RAN];
bool M[RAN];
vector <par>V[RAN];

void dfs(int nod, int can, int d){
         if(!nod && can == n)
            sol++;
         for(int i = 0; i < V[nod].size(); i++){
             int newn = V[nod][i].first;
             int dir = V[nod][i].second;
             if(dir != d && !M[newn]){
                M[newn] = true;
                dfs(newn, can+1, dir);
                M[newn] = false;
             }
         }
}

int main (){
    
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);   	
    
    scanf("%d\n", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d %d\n", &F[i], &C[i]);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(F[i] == F[j]){
               nod = i;
               newn = j;
               if(C[i] > C[j])
                  swap(nod, newn);
               V[nod].push_back(par(newn, 1));
               V[newn].push_back(par(nod, 2));
            }
            else{
              if(C[i] == C[j]){
                  nod = i;
                  newn = j;
                  if(F[i] > F[j])
                     swap(nod, newn);
                  V[nod].push_back(par(newn, 3));
                  V[newn].push_back(par(nod, 4));
              }
           }
        }
    }
    n++;
    dfs(0, 0, -1);
    
    printf("%d\n",sol);
    
    return 0; 
    }
