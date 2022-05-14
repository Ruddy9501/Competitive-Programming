/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007-2008/marzo/plata
Viaje Vacuno/ ctravel
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int F, C, N, f, c, ff, fc, sol, newf, newc;
int S[105][105][16];
char M[105][105];
const int mf[4] = {0, 0,-1, 1},
          mc[4] = {1,-1, 0, 0};

int main(){

    freopen ("ctravel.in", "r", stdin);
    freopen ("ctravel.out", "w", stdout);

    scanf ("%d %d %d\n", &F, &C, &N);
    for (int i = 1; i <= F; i++){
         for (int j = 1; j <= C; j++)
              scanf ("%c", &M[i][j]);
         scanf ("\n");
    }

    scanf ("%d %d %d %d", &f,&c,&ff,&fc);
    S[f][c][0] = 1;
    for (int i = 1; i <= N; i++){
         for (int j = 1; j <= F; j++){
              for (int k = 1; k <= C; k++){
                   if (M[j][k] == '*')
                       continue;
                   for (int l = 0; l < 4; l++){
                        newf = j + mf[l];
                        newc = k + mc[l];
                        if (M[j][k] == '.')
                            S[j][k][i] += S[newf][newc][i-1];
                   }
              }
         }
    }

    printf ("%d\n", S[ff][fc][N]);

    return 0;
}
