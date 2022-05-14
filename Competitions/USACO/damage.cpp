/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/ORO/2008-2009/enero
Daño de Terremoto/damage
BFS
*/
#include <queue>
#include <vector>
#include <cstdio>

#define RAN 100005
#define RAN1 30005
using namespace std;

queue <int>Q;
vector <int>V[RAN];

int nd, nc, nm, con, x, y, la, nod, newn;
bool M[RAN1];

int main(){

    freopen ("damage.in", "r", stdin);
    freopen ("damage.out", "w", stdout);

    scanf ("%d %d %d", &nd, &nc, &nm);
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d", &x, &y);
         if (x != y)
             V[x].push_back(y),
             V[y].push_back(x);
    }

    for (int i = 1; i <= nm; i++){
         scanf ("%d", &x);
         la = V[x].size();
         for (int j = 0; j < la; j++)
              M[V[x][j]] = 1;
    }

    Q.push (1);
    M[1] = true, con = 1;
    while (!Q.empty()){
           nod = Q.front();
           Q.pop();
           la = V[nod].size();
           for (int i = 0; i < la; i++){
                newn = V[nod][i];
                if (!M[newn]){
                    M[newn] = 1;
                    con++;
                    Q.push (newn);
                }
           }
    }

    printf ("%d\n", nd-con);

    return 0;
}
