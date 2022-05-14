/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/2006/noviembre/oro
Bloques de Caminos/block
K-> camino minimo
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

#define oo 1 << 30
#define RAN 5005
using namespace std;
typedef pair<int, int>par;

int c, nd, nc, nod, cos, newn, newc;
int C[RAN], K[RAN], R[RAN];
vector <par>V[RAN];
priority_queue <par, vector<par>, greater<par> >Q;

int main(){

    freopen ("block.in", "r", stdin);
    freopen ("block.out", "w", stdout);

    scanf ("%d %d", &nd, &nc);
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d %d", &nod, &newn, &cos);
         V[nod].push_back(par(newn, cos));
         V[newn].push_back(par(nod, cos));
    }

    for (int i = 1; i <= nd; i++){
         R[i] = V[i].size();
         C[i] == oo;
    }

    C[1] = 0;
    Q.push(par(0, 1));
    while (!Q.empty()){
           cos = Q.top().first;
           nod = Q.top().second;
           Q.pop();
           if (nod == nd){
               c++;
               if (c == 2){
                   printf ("%d\n", cos);
                   return 0;
               }
           }
           if (K[nod] > 2)
                    continue;
           K[nod]++;
           for (int i = 0; i < R[nod]; i++){
                newn = V[nod][i].first;
                newc = V[nod][i].second + cos;
                Q.push(par(newc, newn));
           }
    }

   // printf ("%d\n", C[nd]]);

    return 0;
}
