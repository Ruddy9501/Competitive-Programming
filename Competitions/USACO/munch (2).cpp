/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2007-08\Abril-Open\Data\Bronce
Masticando\munch
BFS
*/
#include <queue>
#include <cstdio>
#include <cstring>

#define RAN 110
#define oo 1 << 30
using namespace std;
typedef pair<int, int>par;

int F, C, f, c, nc, nf, ii, ij, fi, fj, C1[RAN][RAN];
char A[RAN][RAN];
const int mf[] = {0,0,-1,1},
          mc[] = {1,-1,0,0};

queue <par>Q;

void bfs (){
     Q.push(par(ii, ij));
     C1[ii][ij] = 0;
     while (!Q.empty()){
            f = Q.front().first;
            c = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++){
                 nf = f + mf[i];
                 nc = c + mc[i];
                 if (C1[nf][nc] > C1[f][c]+1 && A[nf][nc] == '.'){
                     C1[nf][nc] = C1[f][c]+1;
                     Q.push(par(nf, nc));
                 }
            }
     }
}

int main(){

    freopen ("munch.in", "r", stdin);
    freopen ("munch.out", "w", stdout);

    scanf ("%d %d", &F, &C);
    for (int i = 1; i <= F; i++){
         scanf ("\n");
         for (int j = 1; j <= C; j++){
              C1[i][j] = oo;
              scanf ("%c", &A[i][j]);
              if (A[i][j] == 'B'){
                  ii = i;
                  ij = j;
                  A[i][j] = '.';
              }
              if (A[i][j] == 'C'){
                  fi = i;
                  fj = j;
                  A[i][j] = '.';
              }
         }
    }

    bfs ();

    printf ("%d\n", C1[fi][fj]);

    return 0;
}
