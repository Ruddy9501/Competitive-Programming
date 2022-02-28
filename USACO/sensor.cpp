/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
NACIONAL/2008/DIA 2B
BFS para matriz
*/
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>

#define oo 1 << 30
#define RAN 305
using namespace std;
typedef pair <int, int>par;

const int mf[4] = { 0, 0, 1,-1},
          mc[4] = { 1,-1, 0, 0},
          cc[4]  = { 0, 0, 1, 1};
int Fx, Fy, Ix, Iy, F, C, n, f, c, nc, nf, x, y, f1, c1;
int CC[RAN][RAN], A[RAN][RAN];
char M[RAN][RAN];
par R[RAN][RAN];
queue <par>Q;
stack <par>P;


int main(){

    freopen ("sensor.in", "r", stdin);
    freopen ("sensor.out", "w", stdout);

    scanf ("%d %d", &F, &C);
    scanf ("%d %d %d %d", &Ix, &Iy, &Fx, &Fy);
    scanf ("%d", &n);

    for (int i = 1; i <= F; i++)
         for (int j = 1; j <= C; j++){
              M[i][j] = '.';
              CC[i][j] = oo;
         }

    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &x, &y);
         M[x][y] = '*';
    }

    CC[Ix][Iy] = 0;
    Q.push(par(Ix, Iy));
    while (!Q.empty()){
           f = Q.front().first;
           c = Q.front().second;
           Q.pop();
           for (int i  = 0; i < 4; i++){
                nf = mf[i] + f;
                nc = mc[i] + c;
                if (M[nf][nc] == '.')
                if ((CC[nf][nc] > CC[f][c]+cc[i]) || (CC[nf][nc] == CC[f][c]+cc[i] && A[nf][nc] > A[f][c]+1)){
                    CC[nf][nc] = CC[f][c]+cc[i];
                    Q.push(par(nf, nc));
                    R[nf][nc].first = f;
                    R[nf][nc].second = c;
                    A[nf][nc] = A[f][c] + 1;
                }
           }
    }

    printf ("%d\n%d\n",  A[Fx][Fy] ,CC[Fx][Fy]);

    f = Fx;
    c = Fy;
    P.push (par(f,c));
    while (f != Ix || c != Iy){
           f1 = f;
           c1 = c;
           f = R[f1][c1].first;
           c = R[f1][c1].second;
           P.push (par(f,c));
    }
    P.pop();
    while (!P.empty()){
           printf ("%d %d\n", P.top().first, P.top().second);
           P.pop();
    }

    return 0;
}
