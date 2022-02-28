/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/2013-2014/septiembre/oro
Planeación de Vacaciones/vacationgold
dijkstra
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

#define oo 1 << 30
#define RAN 20005
using namespace std;
typedef pair<long long, int> par;
typedef pair<int, int> par1;

int n, m, k, p, con, c, nod, newn, cent;
long long C[2][205][RAN], sum_tot, cos, newc, sum;
bool M[RAN];

vector <par1> V[2][RAN];
priority_queue <par, vector<par>, greater<par> >Q;

void dikstra (int nod, int pos){
     fill (C[pos][c], C[pos][c]+n+1, oo);
     fill (M, M+n+1, false);
     Q.push(par(0, nod));
     C[pos][c][nod] = 0;
     while (!Q.empty()){
            cos = Q.top().first;
            nod = Q.top().second;
            Q.pop();
            if (M[nod])continue;
            M[nod] = 1;
            for (int i = 0; i < V[pos][nod].size(); i++){
                 newn = V[pos][nod][i].first;
                 newc = V[pos][nod][i].second + cos;
                 if (C[pos][c][newn] > newc){
                     C[pos][c][newn] = newc;
                     Q.push(par(newc, newn));
                 }
            }
     }
}

int main(){

    freopen ("vacationgold.in", "r", stdin);
    freopen ("vacationgold.out", "w", stdout);

    scanf ("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 1; i <= m; i++){
         scanf ("%d%d%d", &nod, &newn, &cos);
         V[0][newn].push_back(par(nod, cos));
         V[1][nod].push_back(par(newn, cos));
    }

    for (int i = 1; i <= k; i++){
         scanf ("%d", &cent);
         c++;
         dikstra (cent, 0);
         dikstra (cent, 1);
    }

    for (int i = 1; i <= p; i++){
         scanf ("%d%d", &nod, &newn);
         sum = oo;
         for (int j = 1; j <= k; j++)
              sum = min (sum, (C[0][j][nod]+C[1][j][newn]));
         if (sum != oo){
             sum_tot += sum;
             con++;
         }
    }

    printf ("%d\n%lld\n", con, sum_tot);

    return 0;
}
