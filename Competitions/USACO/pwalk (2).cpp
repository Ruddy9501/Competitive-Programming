/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/octubre/bronce
Caminando entre Pastizales/pwalk
BRUTE FORSE -> n disktra
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

#define RAN 1005
#define oo 1 << 30
using namespace std;
typedef pair<int, int>par;

int n, m, a, b, c, cos, nod, newc, newn, C[RAN][RAN];
vector <par>V[RAN];
priority_queue <par, vector<par>, greater<par> >Q;

void bfs(int pos){
     Q.push(par(0, pos));
     while (!Q.empty()){
            cos = Q.top().first;
            nod = Q.top().second;
            Q.pop();
            for (int j = 0; j < V[nod].size(); j++){
                 newn = V[nod][j].first;
                 newc = V[nod][j].second + cos;
                 if (C[pos][newn] > newc){
                     C[pos][newn] = newc;
                     C[newn][pos] = min (C[newn][pos], newc);
                     Q.push(par(newc, newn));
                 }
            }
     }
}

int main(){

    freopen ("pwalk.in", "r", stdin);
    freopen ("pwalk.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i < n; i++){
         scanf ("%d %d %d", &a, &b, &c);
         V[a].push_back(par(b, c));
         V[b].push_back(par(a, c));
    }

    for (int i = 1; i <= n; i++){
         fill (C[i] + 1, C[i] + n + 1, oo);
         C[i][i] = 0;
         bfs (i);
    }

    for (int i = 1; i <= m; i++){
         scanf ("%d %d", &a, &b);
         printf ("%d\n", C[a][b]);
    }

    return 0;
}
