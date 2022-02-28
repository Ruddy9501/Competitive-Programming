/*
Ruddy Guerrero Alvarez
revamp/solucion/FEB09
*/
#include <queue>
#include <cstdio>
#include <vector>

#define RAN 500002
using namespace std;
typedef pair<int, int>par;

int a, b, c, nod, newn, cos, newc, k, K, nd, nc;
int C[21][RAN];

struct tri{
       int nod, cos, k;
       tri (int a = 0, int b = 0, int c = 0){
            cos = a;
            nod = b;
            k = c;
       }
       bool operator <(const tri &R)
       const{
            return R.cos < cos;
       }
};

vector <par> V[RAN];
priority_queue <tri> Q;

int main(){

    freopen ("revamp.in", "r", stdin);
    freopen ("revamp.out", "w", stdout);

    scanf ("%d %d %d", &nd, &nc, &K);
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d %d", &a, &b, &c);
         V[a].push_back(par(b, c));
         V[b].push_back(par(a, c));
    }

    for (int i = 0; i <= K; i++)
         for (int j = 2; j <= nd; j++)
              C[i][j] = 1 << 30;

    Q.push(tri(0, 1, 0));
    while (!Q.empty()){
           cos = Q.top().cos;
           nod = Q.top().nod;
           k = Q.top().k;
           Q.pop();
           int la = V[nod].size();
           for (int i = 0; i < la; i++){
                newn = V[nod][i].first;
                newc = V[nod][i].second + cos;
                if (C[k][newn] > newc){
                    C[k][newn] = newc;
                    Q.push(tri(newc, newn, k));
                }
                if (C[k+1][newn] > cos && k+1 <= K){
                    C[k+1][newn] = cos;
                    Q.push(tri(cos, newn, k+1));
                }
           }
    }

    int sol = 1 << 30;
    for (int i = 0; i <= K; i++)
         sol = min (sol, C[i][nd]);

    printf ("%d\n", sol);

    return 0;
}
