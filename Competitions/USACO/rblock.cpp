/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2011-2012/plata/diciembre
Camino de Bloques/rblock
BFS
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define oo 1 << 30
#define RAN 105
using namespace std;
typedef pair <int, int>par;

int nd, nc, nod, cos, newn, newc, sol;
int C[RAN], Pad[RAN], K[RAN][RAN];
queue <par>Q1;
priority_queue <par, vector <par>, greater<par> >Q;
vector <int>V[RAN];

void bfs(){
         fill (C + 2, C + nd + 1, oo);
         Q.push(par(0,1));
         int nod, newn, cos, newc;
         while (!Q.empty()){
                cos = Q.top().first;
                nod = Q.top().second;
                Q.pop();
                for (int i = 0; i < V[nod].size(); i++){
                     newn = V[nod][i];
                     newc = K[nod][newn] + cos;
                     if (C[newn] > newc){
                         C[newn] = newc;
                         Pad[newn] = nod;
                         Q.push(par(newc, newn));
                     }
                 }
         }
}

int main(){

    freopen ("rblock.in", "r", stdin);
    freopen ("rblock.out", "w", stdout);

    scanf ("%d %d", &nd, &nc);
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d %d", &nod, &newn, &cos);
         V[nod].push_back(newn);
         V[newn].push_back(nod);
         K[nod][newn] = cos;
         K[newn][nod] = cos;
    }

    bfs ();

    int s = C[nd];

    nod = nd;
    while (Pad[nod] != 0){
           Q1.push(par(Pad[nod], nod));
           nod = Pad[nod];
    }

    while (!Q1.empty()){
           nod = Q1.front().first;
           newn = Q1.front().second;
           Q1.pop();
           K[nod][newn] *= 2;
           K[newn][nod] *= 2;
           bfs();
           sol = max (sol, C[nd]);
           K[nod][newn] /= 2;
           K[newn][nod] /= 2;
    }

    printf ("%d\n", sol - s);

    return 0;
}
