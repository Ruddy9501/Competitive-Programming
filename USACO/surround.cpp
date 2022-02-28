/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/febrero/plata
Cercando las Islas/surround
BRUTE FORCE
*/
#include <queue>
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 505
using namespace std;
typedef pair <int, int>par;

int n, a, b, a1, b1, id, cos, nod, con, sol, s = 1 << 30, I[RAN], A[RAN][RAN];
bool M[RAN];
vector <int>V[RAN];
priority_queue<par, vector<par>, greater<par> >Q;

int main(){

    freopen ("surround.in", "r", stdin);
    freopen ("surround.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         if (a != a1 && b != b1 && a != b1 && b != b1){
             con++;
             I[a] = con;
             I[b] = con;
         }
          else{
             I[a] = con;
             I[b] = con;
          }
          a1 = a;
          b1 = b;
    }

    for (int i = 1; i <= n; i++){
         V[I[i]].push_back(i);
         for (int j = 1; j <= n; j++)
              scanf ("%d", &A[i][j]);
    }

    for (int i = 1; i <= con; i++){
         for (int j = 0; j < V[i].size(); j++){
              nod = V[i][j];
              for (int k = 1; k <= n; k++)
                   if (I[k] != i)
                       Q.push(par(A[nod][k], I[k]));
         }
         sol = 0;
         fill (M + 1, M + con + 1, false);
         while (!Q.empty()){
                cos = Q.top().first;
                id = Q.top().second;
                Q.pop();
                if (M[id] == false){
                    sol += (2 * cos);
                    M[id] = true;
                }
         }
         if (s > sol)
             s = sol;
    }

    printf ("%d\n", s);

    return 0;
}
