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

#define RAN 1005
#define MAX 105
#define oo 1 << 29

using namespace std;
typedef pair<double, int>par;

int newn, nod, nc, n, x, y;
int X[MAX], Y[MAX], nf[MAX];
double newc, cos1;
double C[RAN];
bool M[MAX];
vector <int>V[RAN];
priority_queue<par , vector<par>, greater<par> >Q;

int main (){
    
    freopen("gondor.in","r",stdin);
    freopen("gondor.out","w",stdout);   	
    
    scanf ("%d\n", &n);
    
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &x, &y);
         X[i] = x;
         Y[i] = y;
         scanf ("%d", &nf[i]);
         for (int j = 1; j <= n-1; j++){
              scanf("%d", &x);
              V[i].push_back(x);
         }
    }
    
    fill(C + 2, C + n + 1, oo);
    
    Q.push (par( 0, 1));
    while (!Q.empty()){
           cos1 = Q.top().first;
           nod = Q.top().second;
           Q.pop();
           M[nod] = true;
           for (int i = 0; i < V[nod].size(); i++){
               if(nf[nod] == 0)
                  break;
                newn = V[nod][i];
                newc = sqrt((X[nod] - X[newn]) * (X[nod] - X[newn]) + 
                (Y[nod] - Y[newn]) * (Y[nod] - Y[newn])) + cos1;
                if (!M[newn])
                    nf[nod]--; 
                if (newc < C[newn]){   
                    C[newn] = newc;
                    Q.push(par(newc, newn));      
                }
           }
    }
    
    for (int i = 1; i <= n; i++)
         printf("%.10lf\n",C[i]);
    
    return 0; 
    }
