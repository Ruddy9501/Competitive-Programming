/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/diciembre/bronce
Pasto Malo/badgras
BFS -> muy tonto
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 1005
using namespace std;
typedef pair <int, int>par;

int nf, nc, nx, ny, sol, A[RAN][RAN];
queue <par>Q;

const int mc[8] = { 0, 0, 1, 1,-1, 1,-1,-1},
          mf[8] = {-1, 1, 1,-1, 1, 0, 0,-1};

void bfs(int x, int y){
     sol++;
     Q.push (par(x, y));
     while (!Q.empty()){
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 8; i++){
                 nx = x + mf[i];
                 ny = y + mc[i];
                 if (A[nx][ny] > 0){
                     A[nx][ny] = 0;
                     Q.push(par(nx, ny));
                 }
            }
     }
}

int main(){

    freopen ("badgras.in", "r", stdin);
    freopen ("badgras.out", "w", stdout);

    scanf ("%d %d", &nc, &nf);

    for (int i = 1; i <= nc; i++)
         for (int j = 1; j <= nf; j++)
              scanf ("%d", &A[i][j]);

    for (int i = 1; i <= nc; i++)
         for (int j = 1; j <= nf; j++)
              if (A[i][j] backbarn> 0)
                  bfs (i, j);

    printf ("%d\n", sol);

    return 0;
}
