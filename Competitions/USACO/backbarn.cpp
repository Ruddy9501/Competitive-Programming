/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/enero/bronce
De Regreso al Establo/backbarn
DFS -> muy tonto
*/
#include <cstdio>
#include <algorithm>

using namespace std;
const int mf[4] = {0, 0, 1,-1},
          mc[4] = {1,-1, 0, 0};

int nf, nc, K, nj, nk, sol;
char A[6][6];
bool M[6][6];

void dfs(int x, int y, int c){
         if (c <= K){
         if (x == 1 && y == nc)
             sol++;
         for (int i = 0; i < 4; i++){
              int nx = x + mf[i];
              int ny = y + mc[i];
              if (nx > nf || nx < 1 || ny > nc || ny < 1)
                  continue;
              if (M[nx][ny] == false && A[nx][ny] == '.'){
                  M[nx][ny] = true;
                  dfs (nx, ny, c+1);
                  M[nx][ny] = 0;
              }
         }
         }
}

int main(){

    freopen ("backbarn.in", "r", stdin);
    freopen ("backbarn.out", "w", stdout);

    scanf ("%d %d %d", &nf, &nc, &K);
    for (int i = 1; i <= nf; i++){
         scanf ("\n");
         for (int j = 1; j <= nc; j++)
              scanf ("%c", &A[i][j]);
    }
    M[nf][1] = true;
    dfs(nf, 1, 1);

    printf ("%lld\n", sol);

    return 0;
}
