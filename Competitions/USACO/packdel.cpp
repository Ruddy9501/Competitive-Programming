#include <queue>
#include <cstdio>
/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACOO/2010-2011/marzo/plata
Envio de Paquetes/packdel
dijktra
*/
#include <vector>
#include <algorithm>

#define RAN 60000
using namespace std;

typedef pair<int, int>par;
int nod, newn, cos, newc, n, m, C[RAN];
vector <par>V[RAN];
priority_queue <par, vector<par>, greater<par> >Q;

int main (){
    
    freopen ("packdel.in", "r", stdin);
    freopen ("packdel.out", "w", stdout);
    
    scanf ("%d %d", &n, &m);
    for (int i = 1 ; i <= m; i++){
         scanf ("%d %d %d", &nod, &newn, &cos);
         V[nod].push_back(par(newn, cos));    
          V[newn].push_back(par(nod, cos)); 
    }
    
    fill(C + 2, C+ n + 1, 1 << 29);
    Q.push(par(0,1));
    while (!Q.empty()){
          nod = Q.top().second;
          cos = Q.top().first;
          Q.pop();
          for (int i = 0; i < V[nod].size(); i++){
               newn = V[nod][i].first;
               newc = V[nod][i].second + cos;
               if (C[newn] > newc){
                   C[newn] = newc;
                   Q.push(par(newc, newn));
               }
          } 
    }
    
    printf ("%d\n", C[n]);
    
    return 0;
    }
