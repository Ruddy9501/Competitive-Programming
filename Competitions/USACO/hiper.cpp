/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Prueba Final #3 PSN 2013
Hipertubos hiper
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 100010
#define oo 1 << 30
using namespace std;
typedef pair<int, int>par;

priority_queue <par, vector<par>, greater<par> >Q;
vector <int>V[RAN], V1[RAN];

int n, k, m, cos, la, nod, newn, A[1010], C[RAN];
bool M[RAN];

int main(){

    freopen ("HIPER.in", "r", stdin);
    freopen ("HIPER.out", "w", stdout);

    scanf ("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= m; i++){
         for (int j = 1, a; j <= k; j++){
              scanf ("%d", &a);
              V[a].push_back(i);
              V1[i].push_back(a);
         }
    }

   for (int i = 2; i <= n; i++)
        C[i] = oo;

    Q.push(par(1,1));
    while (!Q.empty()){
           cos = Q.top().first;
           nod = Q.top().second;
           Q.pop();
           la = V[nod].size();
           for (int i = 0; i < la; i++){
                int nt = V[nod][i];
                if (M[nt])continue;
                M[nt] = 1;
                int lb = V1[nt].size();
                for (int j = 0; j < lb; j++){
                     newn = V1[nt][j];
                     if (C[newn] > cos+1){
                         C[newn] = cos + 1;
                         Q.push(par(cos+1, newn));
                      }
                }
           }
    }

    if (C[n] == oo)
        C[n] = -1;

    printf ("%d\n", C[n]);

    return 0;
}
