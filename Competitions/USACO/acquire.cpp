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
typedef pair<int, int>par;

int nod, newn, cos, i, n, f;
int C[RAN], p[RAN];
vector <int>V[RAN];
stack <int>P;
priority_queue<par, vector <par>, greater<par> >Q;

int main (){
    
    freopen("acquire.in","r",stdin);
    freopen("acquire.out","w",stdout);   	
    
    scanf ("%d %d\n", &n, &f);
    
    for (int i = 1; i <= n; i++){
         scanf ("%d %d\n", &nod, &newn);
         V[nod].push_back(newn); 
    }
    
    fill (C + 2, C + n + 1, oo);
    
    Q.push(par(1,1));
    while (!Q.empty()){
           cos = Q.top().first;
           nod = Q.top().second;
           Q.pop();
           for (int i = 0; i < V[nod].size(); i++){
                newn = V[nod][i];
                if (C[newn] > cos + 1){
                    C[newn] = cos + 1;
                    Q.push(par(cos+1, newn));
                    p[newn] = nod;  
                }
           }
    }
    
    if (C[f] == oo){
        printf ("-1");
        return 0;
    } 
     
    P.push(f);
    int i = p[f];
    P.push(i);
    while (i != 1){
           i = p[i];
           P.push(i);
    }
    
    printf ("%d\n",C[f]);
    while (!P.empty()){
           printf ("%d\n",P.top()); 
           P.pop(); 
    }
    
    return 0; 
    }
