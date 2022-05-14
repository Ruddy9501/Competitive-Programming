/*
Ruddy Guerrero Alvraez
Vila Clara -> Caibarien
/USACO/Problems/2007/nov07/Bronze
Evite los Lagos/lake
BFS
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 110
using namespace std;
typedef pair<int, int>par;

int F, C, n, s, f, c, nf, nc, can;
bool M[RAN][RAN];
const int mf[] = {  0,  0,  1, -1},
          mc[] = {  1, -1,  0,  0};

queue <par>Q;

int bfs(int f, int c){
    can = 0;
    Q.push(par(f, c));
    while (!Q.empty()){
           f = Q.front().first;
           c = Q.front().second;
           Q.pop();
           for (int i = 0; i < 4; i++){
                nf = f + mf[i];
                nc = c + mc[i];
                if (M[nf][nc]){
                    M[nf][nc] = 0;
                    Q.push(par(nf, nc));
                    can++;
                }
           }
    }
    return can;
}

int main(){

    freopen ("lake.in", "r", stdin);
    freopen ("lake.out", "w", stdout);

    scanf ("%d %d %d", &F, &C, &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &f, &c);
         M[f][c] = 1;
    }

    for (int i = 1; i <= F; i++)
         for (int j = 1; j <= C; j++)
              if (M[i][j])
                  s = max (s, bfs(i, j));

    printf ("%d\n", s);

    return 0;
}
