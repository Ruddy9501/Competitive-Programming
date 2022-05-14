/*
Ruddy Guerrero Alvarez
Villa Clara -> CAibarien
USACO\Problems\2007\feb07\Bronze
Estanque de Nenúfares Bronce\bronlily
BFS
*/
#include <queue>
#include <cstdio>

#define RAN 40
#define oo 1 << 30
using namespace std;

int F, C, m, f, c, nf, nc, cos, sf, sc, a, ii, ij, fi, fj, C1[RAN][RAN];
bool M[RAN][RAN];

int mf[] = {-1, -1,  1,  1,  1,  1, -1, -1},
    mc[] = {-1,  1, -1,  1, -1,  1,  1, -1};

struct tri{
       int cos, f, c;
       tri (int a = 0, int b = 0, int d = 0){
            cos = a;
            f = b;
            c = d;
       }
       bool operator <(const tri &R)
       const{
             return R.cos < cos;
       }
};

priority_queue<tri> Q;

void bfs (){
     Q.push(tri(0, ii, ij));
     C1[ii][ij] = 0;
     while (!Q.empty()){
            cos = Q.top().cos;
            f = Q.top().f;
            c = Q.top().c;
            Q.pop();
            for (int i = 0; i < 8; i++){
                 nf = f + mf[i];
                 nc = c + mc[i];
                 if (M[nf][nc] && C1[nf][nc] > cos+1){
                     C1[nf][nc] = cos + 1;
                     Q.push(tri(cos+1, nf, nc));
                 }
            }
     }
}

int main(){

    freopen ("bronlily.in", "r", stdin);
    freopen ("bronlily.out", "w", stdout);

    scanf ("%d %d %d %d", &F, &C, &sf, &sc);

    for (int i = 0; i < 4; i++)
         mf[i] *= sf, mc[i] *= sc;
    for (int i = 4; i < 8; i++)
         mf[i] *= sc, mc[i] *= sf;

    for (int i = 1; i <= F; i++)
         for (int j = 1; j <= C; j++){
              scanf ("%d", &a);

              if (a == 1)
                  M[i][j] = 1;

              if (a == 3){
                  ii = i;
                  ij = j;
              }
              else
                  if (a == 4){
                      M[i][j] = 1;
                      fi = i;
                      fj = j;
                  }

    }

    for (int i = 1; i <= F; i++)
         fill (C1[i] + 1, C1[i] + C + 1, oo);

    bfs ();

    printf ("%d\n", C1[fi][fj]);

    return 0;
}
