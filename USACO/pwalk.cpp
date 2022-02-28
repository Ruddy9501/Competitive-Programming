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

#define RAN 1005
#define oo 1 << 29

using namespace std;
typedef pair <int, int>par; 
int newn, newc, nod, cos, nd, na, x, y, z;
int C[RAN], S[RAN];
vector <par>V[RAN];
priority_queue<par , vector<par>, greater<par> >Q;

void dijktra(int ini, int fin, int n){
             fill(C + 1, C + nd + 1, oo);
             Q.push(par(0, ini));
             while (!Q.empty()){
                    cos = Q.top().first;            
                    nod = Q.top().second;
                    Q.pop();
                    for (int i = 0; i < V[nod].size(); i++){
                         newn = V[nod][i].first;
                         newc = V[nod][i].second + cos;   
                         if (newc < C[newn]){
                             C[newn] = newc;
                             Q.push(par(newc, newn)); 
                             if (newn == fin){
                                 S[n] = newc;  
                                 while (!Q.empty())
                                        Q.pop();  
                             }                        
                         }
                    }
             }
}

int main (){
    
    freopen ("pwalk.in","r",stdin);
    freopen ("pwalk.out","w",stdout);
    
    scanf ("%d %d\n", &nd, &na);
    
    for (int i = 1; i < nd; i++){
         scanf("%d %d %d\n", &x, &y, &z);
         V[x].push_back(par(y,z));
         V[y].push_back(par(x, z));
    }   	
    
    for (int i = 1; i <= na; i++){
         scanf("%d %d\n", &x, &y);
         dijktra(x, y, i);
    } 
    
    for(int i = 1; i <= na; i++)
        printf("%d\n",S[i]); 
     
    return 0; 
    }
