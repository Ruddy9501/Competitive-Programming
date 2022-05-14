/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2007-08\Abril-Open\Data\Bronce
Agua Fría Clara\coldwat
BFS
*/
#include <queue>
#include <vector>
#include <cstdio>

#define RAN 99999
using namespace std;

int m, n, a, b, c, nod, newn, C[RAN*3];

vector <int>V[RAN];
queue <int>Q;

void bfs(){
     Q.push(1);
     C[1] = 1;
     while (!Q.empty()){
            nod = Q.front();
            Q.pop();
            if (V[nod].size() != 0)
            for (int i = 0; i < 2; i++){
                 newn = V[nod][i];
                 C[newn] = C[nod]+1;
                 Q.push(newn);
            }
     }
}

int main(){

    freopen ("coldwat.in", "r", stdin);
    freopen ("coldwat.out", "w", stdout);

    scanf ("%d %d", &m, &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d %d", &a, &b, &c);
         V[a].push_back(b);
         V[a].push_back(c);
    }

    bfs ();

    for (int i = 1; i <= m ; i++)
         printf ("%d\n", C[i]);

    return 0;
}
