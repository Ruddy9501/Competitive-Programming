/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/diciembre/bronce
Damas/chkr
DFS -> bueno
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 1005
using namespace std;
typedef pair <int, int>par;
const int mf[4] = {-1, -1, 1,  1},
          mc[4] = { 1, -1, 1, -1};

int n, ca;
char A[RAN][RAN];
queue <par>P;

void dfs (int x, int y, int c){
          if (c == ca){
              while (!P.empty()){
                     printf ("%d %d\n", P.front().first, P.front().second);
                     P.pop();
              }
              exit (0);
          }
          for (int i = 0; i < 4; i++){
               if (A[x+mf[i]][y+mc[i]] == 'o' && A[x+2*mf[i]][y+2*mc[i]] == '+'){
                   A[x+mf[i]][y+mc[i]] = '+';
                   P.push(par(x+2*mf[i], y+2*mc[i]));
                   dfs(x+2*mf[i], y+2*mc[i], c+1);
                   P.pop();
                   A[x+mf[i]][y+mc[i]] = 'o';

               }
          }
}

int main(){

    freopen ("chkr.in", "r", stdin);
    freopen ("chkr.out",  "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("\n");
         for (int j = 1; j <= n; j++){
              scanf ("%c", &A[i][j]);
              if (A[i][j] == 'o')
                  ca++;
         }
    }

    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
              if (A[i][j] == 'K'){
                  P.push(par(i, j));
                  dfs (i, j, 0);
                  P.pop();
         }

    printf ("impossible");

    return 0;
}
