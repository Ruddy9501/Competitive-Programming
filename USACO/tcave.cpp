/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/open/bronce
Cueva del Tesoro/tcave
disktra
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 5005
#define oo 1 << 30
using namespace std;
typedef pair<int, int>par;

int n, m, T, a, b, c, cos, nod, newn, R[RAN], C[RAN];
vector <int>V[RAN];
priority_queue <par, vector<par>, greater<par> >Q;

void imp(int p){
         if (p != 1)
             imp(R[p]);
         printf ("%d\n", p);
}

int main(){

    freopen ("tcave.in", "r", stdin);
    freopen ("tcave.out", "w", stdout);

    scanf ("%d %d %d", &n, &m, &T);
    for (int i = 1; i <= m; i++){
         scanf ("%d %d %d", &a, &b, &c);
         V[a].push_back(b);
         V[a].push_back(c);
    }

    fill (C + 2, C + n + 1, oo);
    C[1] = 1;
    Q.push(par(1, 1));
    while (!Q.empty()){
           cos = Q.top().first;
           nod = Q.top().second;
           Q.pop();
           for (int i = 0; i < V[nod].size(); i++){
                newn = V[nod][i];
                if (C[newn] > cos+1){
                    C[newn] = cos+1;
                    R[newn] = nod;
                    Q.push(par(cos+1, newn));
                }
           }
    }

    printf ("%d\n", C[T]);
    imp(T);
    return 0;
}
