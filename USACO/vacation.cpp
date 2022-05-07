/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2010-11/November/Problems/Gold
Visitando Vacas/vacation
DFS/divide y venceras
*/
#include <cstdio>
#include <vector>
#include <algorithm>

#define RAN 50010
using namespace std;

int V[RAN], NV[RAN], a, b, n;
vector <int>A[RAN];

void dfs (int nod, int pad){
          int la = A[nod].size();
          V[nod] = 1;
          NV[nod] = 0;
          for (int i = 0; i < la; i++){
               int newn = A[nod][i];

               if (newn == pad)continue;

               dfs (newn, nod);

               V[nod] += NV[newn];
               NV[nod] += max(NV[newn], V[newn]);
          }
}

int main(){

    freopen ("vacation.in", "r", stdin);
    freopen ("vacation.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i < n; i++){
         scanf ("%d %d", &a, &b);
         A[a].push_back(b);
         A[b].push_back(a);
    }

    dfs (1, -1);

    printf ("%d\n", max(V[1], NV[1]));

    return 0;
}
