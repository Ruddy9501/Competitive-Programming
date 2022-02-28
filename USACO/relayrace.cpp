/*
Ruddy Guerrero ALvarez
12mo
Villa CLara -> Caibarien
USACO/Problems/2009-10/Abril/Problems/Bronze
Carrera de Relevos/relayrace
Dijkstra
*/
#include <cstdio>
#include <vector>
#include <queue>

#define RAN 1010

using namespace std;
typedef pair<int, int>par;

int mc, la, sol, a, n, m, cos, nod, newn, C[RAN];
bool M[RAN];

vector<int>V[RAN];
priority_queue <par, vector<par>, greater<par> >Q;


int main(){

    freopen ("relayrace.in", "r", stdin);
    freopen ("relayrace.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &C[i], &m);
         for (int j = 1; j <= m; j++){
              scanf ("%d", &a);
              V[i].push_back(a);
         }
    }


    for (int i = 1; i <= n; i++){
         if (!M[i]){
             M[i] = 1;
             Q.push(par(C[i], i));
             mc = C[i];
             while (!Q.empty()){
                    cos = Q.top().first;
                    nod = Q.top().second;
                    Q.pop();
                    la = V[nod].size();
                    for (int i = 0; i < la; i++){
                         newn = V[nod][i];
                         if (!M[newn]){
                             M[newn] = 1;
                             Q.push(par(cos+C[newn], newn));
                             mc = max (mc, cos+C[newn]);
                         }
                    }
             }
             sol += mc;
             mc = 0;
         }
    }

    printf ("%d\n", sol);

    return 0;
}
