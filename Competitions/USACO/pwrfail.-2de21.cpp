/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/

#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define RAN 10005
#define oo 1 << 29

using namespace std;
typedef pair<double, int>par;

int newn, nod, nd, nc, x, y, X[RAN], Y[RAN];
bool M[RAN];
double newc, cos1, C[RAN], n;
vector <par>V[RAN];
priority_queue<par , vector<par>, greater<par> >Q;

int main (){
    
    freopen ("pwrfail.in","r",stdin);
    freopen ("pwrfail.out","w",stdout);   	
     
    scanf ("%d %d\n", &nd, &nc);
    scanf ("%lf\n", &n);
    
    for (int i = 1; i <= nd; i++)
         scanf ("%d %d\n", &X[i], &Y[i]);
    
    for (int i = 1; i <= nd-1; i++){
         for (int j = i+1;  j <= nd; j++){
              cos1 = sqrt((X[i] - X[j]) * (X[i] - X[j]) + 
                     (Y[i] - Y[j]) * (Y[i] - Y[j]));
              if(cos1 <= n){
                 V[i].push_back(par(cos1 * 1000, j));  
                 V[j].push_back(par(cos1 * 1000, i));  
              }
         }
    }
    
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d\n", &x, &y);
         V[x].push_back(par(0, y));                      
         V[y].push_back(par(0, x));      
    }
    
    fill (C + 1, C + nd - 1, oo);
    
    Q.push (par(0, nd));
    while (!Q.empty()){
           cos1 = Q.top().first;
           nod = Q.top().second;
           Q.pop();
           M[nod] = true;
           for (int i  = 0; i < V[nod].size(); i++){
                newc = V[nod][i].first + cos1;
                newn = V[nod][i].second;
                if (C[newn] > newc){
                    C[newn] = newc;
                    Q.push(par(newc, newn));
                }       
           }
    } 
    
    if (C[1] == oo){
        printf("-1\n");
        return 0;
    }
      
    
 
    //C[nd] *= 1000;
    int sol = int(C[nd]);
    printf("%d",sol);
     
    return 0; 
    }
