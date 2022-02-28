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

#define RAN 10000
#define oo 1 << 29

using namespace std;
typedef pair<int,int>par;

int newn, newc, cost, nod, cos, sol, nd, nc, F;
int C[RAN], C1[RAN];
vector <par>V[RAN];
vector <par>V1[RAN];
queue <par> Q1;
priority_queue<par , vector<par>, greater<par> >Q;

void dijktra(int A[], vector <par> V[]){
             fill(A + 1, A + nd + 1, oo);
             Q.push(par(0,F));
             A[F] = 0; 
             while(!Q.empty()){
                   cos = Q.top().first;
                   nod = Q.top().second;
                   Q.pop();
                   for(int i = 0; i < V[nod].size(); i++){
                       newn = V[nod][i].first;
                       newc = V[nod][i].second + cos;
                       if(A[newn] > newc){
                          A[newn] = newc;
                          Q.push(par(newc,newn));
                        }
                    }   
                }
}

int main (){
    
    freopen("sparty.in","r",stdin);
    freopen("sparty.out","w",stdout);
    
    scanf("%d %d %d\n", &nd, &nc, &F);
   
    for(int i = 1; i <= nc; i++){
        scanf("%d %d %d\n", &nod, &newn, &cos);
        V[nod].push_back(par(newn,cos));
        V1[newn].push_back(par(nod,cos));
    }   	 
   
    dijktra(C, V);
	
	dijktra(C1, V1);
    
    for(int i = 1; i <= nd; i++)
        if(C1[i] + C[i] > sol)
           sol = C1[i] + C[i];
    
    printf("%d\n",sol);
       
    return 0; 
    }
