/*
Ruddy Guerrero ALvarez
12mo
Villa CLara -> Caibarien
/USACO/Problems/2009-10/Febrero/Problems/Bronze
Hora de Comer/feedtime
BFS
*/
#include <cstdio>
#include <queue>
#include <cstring>

#define RAN 760
using namespace std;
typedef pair<int, int>par;

int F, C, s, sol, nf, nc, f, c;
char M[RAN][RAN];
const int mf[] = { 0, 0, 1, -1, 1, 1,-1,-1},
          mc[] = {-1, 1, 1, -1,-1, 0, 1, 0};

queue <par>Q;

int bfs(int f, int c){
    Q.push(par(f, c));
    s = 0;
    while(!Q.empty()){
          f = Q.front().first;
          c = Q.front().second;
          Q.pop();
          for (int i = 0; i < 8; i++){
               nf = f+mf[i];
               nc = c+mc[i];
               if (M[nf][nc] == '.'){
                   s++;
                   M[nf][nc] = '*';
                   Q.push(par(nf, nc));
               }
          }
    }
    return s;
}

int main(){

    freopen ("feedtime.in", "r", stdin);
    freopen ("feedtime.out", "w", stdout);

    scanf ("%d %d", &C, &F);
    for (int i = 1; i <= F; i++){
         scanf ("\n");
         for (int j = 1; j <= C; j++)
              scanf ("%c", &M[i][j]);
    }

    for (int i = 1; i <= F; i++)
         for (int j = 1; j <= C; j++)
              if (M[i][j] == '.')
                  sol = max(sol, bfs(i,j));

    printf ("%d\n", sol);

    return 0;
}
