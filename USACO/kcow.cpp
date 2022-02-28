/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/Noviembre/Problems/Bronze
La Vaca Caballerosa/kcow
BFS
*/
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define RAN 160
#define oo 1 << 30
using namespace std;

struct tri{
       int cos, f, c;
       tri (int a = 0, int b = 0, int d = 0){
            cos = a;
            f = b;
            c = d;
       }
       bool operator < (const tri &R)
       const {
             return R.cos < cos;
       }
};

int F, C, ii, ij, fi, fj, f, c, nf, nc, cos, C1[RAN][RAN];
char A[RAN][RAN];
const int mf[] = {-2,  -2, -1, -1,  2,  2,  1,  1},
          mc[] = { 1,  -1,  2, -2,  1, -1,  2, -2};

priority_queue<tri> Q;

void bfs (){
         Q.push(tri(0, ii, ij));
         while (!Q.empty()){
                f = Q.top().f;
                c = Q.top().c;
                cos = Q.top().cos+1;
                Q.pop();
                for (int i = 0; i < 8; i++){
                     nf = mf[i] + f;
                     nc = mc[i] + c;
                     if (C1[nf][nc] > cos && A[nf][nc] == '.'){
                         C1[nf][nc] = cos;
                         Q.push(tri(cos, nf, nc));
                     }
                }
         }
}

int main(){

    freopen ("kcow.in", "r", stdin);
    freopen ("kcow.out", "w", stdout);

    scanf ("%d %d", &C, &F);
    for (int i = 1; i <= F; i++){
         scanf ("\n");
         for (int j = 1; j <= C; j++){
              scanf ("%c", &A[i][j]);
              if (A[i][j] == 'K')
                  ii = i, ij = j;
              if (A[i][j] == 'H')
                  fi = i, fj = j, A[i][j] = '.';
         }
    }

    for (int i = 1; i <= F; i++)
         fill (C1[i] + 1, C1[i] + C + 1, oo);

    bfs ();

    printf ("%d\n", C1[fi][fj]);

    return 0;
}
