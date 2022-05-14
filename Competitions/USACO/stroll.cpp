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

#define RAN 10000
#define oo 1 << 29

using namespace std;
typedef pair<int, int>par;

int newn, cos, nod, sol, n, x, y, c;
bool M[RAN];
vector <int>V[RAN];
queue <par>Q;

int main (){
    
    freopen("stroll.in","r",stdin);
    freopen("stroll.out","w",stdout); 
    
    scanf("%d\n",&n);
    
    c = n;
    for (int i  = 1; i < n; i++){
         scanf("%d %d %d\n", &nod, &x, &y);
         if (x != 0)
             V[nod].push_back(x);
          else
             V[nod].push_back(++c);
         if (y != 0)
             V[nod].push_back(y);
          else                   
             V[nod].push_back(++c);
    } 
    
    Q.push(par(1,0));
    M[1] = true;
    while (!Q.empty()){
           nod = Q.front().first;
           cos = Q.front().second;
           Q.pop();
           for (int i = 0; i < V[nod].size(); i++){
                newn = V[nod][i];
                if (!M[newn]){
                    M[newn] = true;
                    Q.push(par(newn,cos+1));
                    if (cos+1 > sol)
                        sol = cos+1;
                }   
           }
    } 	     
 
    printf ("%d\n",sol);
  
    return 0; 
    }
