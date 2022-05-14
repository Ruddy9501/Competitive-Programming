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

#define RAN 100030
#define MAX 1005
#define oo 1 << 29

using namespace std;
typedef pair<int, int>par;

int C[MAX];
vector <par>V[MAX];
int newn, newc, nod, cos, sol, nc, nd, F, x, y, z;
priority_queue<par ,vector <par>, greater<par> >Q;

int main (){
    
    freopen("bparty.in","r",stdin);
    freopen("bparty.out","w",stdout);   	
    
    scanf("%d %d %d\n", &nd, &nc, &F);
    
    for(int i = 1; i <= nc; i++){
        scanf("%d %d %d\n", &x, &y, &z);
        V[x].push_back(par(y, z));
        V[y].push_back(par(x, z));
    }
    
    fill(C + 1, C + nd + 1, oo);
    
    Q.push(par(0,F));
    while(!Q.empty()){
          nod = Q.top().second;
          cos = Q.top().first;
          Q.pop();
          for(int i = 0; i < V[nod].size(); i++){
              newn = V[nod][i].first;
              newc = V[nod][i].second + cos;
              if(C[newn] > newc){
                 C[newn] = newc;
                 Q.push(par(newc, newn));
              }
         }
    }
    
    for(int i = 1; i <= nd; i++)
        if(C[i] > sol)
           sol = C[i];
        
    printf("%d\n",sol*2);
    
    return 0; 
    }
