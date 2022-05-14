/*
VC1 -> Ruddy Guerrero Alvarez
Provincial - 2012-2013
IPVCE "Ernesto Guevara"
12mo
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int>par;

int n, m, I, F, cos, newn, c, C[1000], x, nod, newc;
priority_queue<par, vector<par>, greater<par> >Q;
vector <par>V[1000];
int main(){

    freopen ("TRAN.in", "r", stdin);
    freopen ("TRAN.out", "w", stdout);

    scanf ("%d%d%d", &n,&I,&F);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &m);
         c = 0;
         for (int j = 1;j <= m; j++){
              scanf ("%d", &x);
              if (j > 1)
                  c = 1;
              V[i].push_back(par(x,c));
         }
    }
    fill (C+1,C+n+1,999999);
    C[I] = 0;
    Q.push(par(0,I));
    while (!Q.empty()){
           nod = Q.top().second;
           cos = Q.top().first;
           Q.pop();
           for (int i = 0; i < V[nod].size(); i++){
                newn = V[nod][i].first;
                newc = cos + V[nod][i].second;
                if (C[newn] > newc){
                    C[newn] = newc;
                    Q.push(par(newc,newn));
                }
           }
    }
    if (C[F] == 999999)
        printf ("-1");
     else
        printf ("%d", C[F]);
    return 0;
}
