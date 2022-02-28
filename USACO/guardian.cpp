/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/noviembre/plata
Cuidando la Granja/guardian
BFS -> bueno
*/
#include <cstdio>
#include <queue>

#define RAN 1000
using namespace std;
typedef pair <int, int>par;

const int mf[9] = { 0, 0, 1, 1, 1,-1,-1,-1},
          mc[9] = { 1,-1, 0, 1,-1, 0,-1, 1};

struct tri{
       int v, x, y;
       tri (int a = 0, int b = 0, int c = 0){
            v = a;
            x = b;
            y = c;
       }
       bool operator <(const tri &R)
       const{
             return R.v > v;
       }
};

int nf, nc, con, x, y, sol, A[RAN][RAN];
bool M[RAN][RAN], mar;
queue <par>Q1;
priority_queue <tri>Q;

void bfs(int x, int y){
         Q1.push(par(x,y));
         while (!Q1.empty()){
                con++;
                x = Q1.front().first;
                y = Q1.front().second;
                Q1.pop();
                for (int i = 0; i < 8; i++){
                     int nx = x + mf[i];
                     int ny = y + mc[i];
                     if (nx > nf || nx < 1 || ny > nc || ny < 1)
                         continue;
                     if (A[nx][ny] <= A[x][y] && M[nx][ny] == false){
                         M[nx][ny] = true;
                         Q1.push(par(nx, ny));
                     }
                }
         }
}

int main(){

    freopen ("guardian.in", "r", stdin);
    freopen ("guardian.out", "w", stdout);

    scanf ("%d %d", &nf, &nc);
    for (int i = 1; i <= nf; i++)
         for (int j = 1; j <= nc; j++){
              scanf ("%d", &A[i][j]);
              Q.push(tri(A[i][j], i, j));
        }

    while (!Q.empty()){
           x = Q.top().x;
           y = Q.top().y;
           Q.pop();
           if (M[x][y] == false){
               sol++;
               bfs(x, y);
           }
    }

    printf ("%d\n", sol);

    return 0;
}
