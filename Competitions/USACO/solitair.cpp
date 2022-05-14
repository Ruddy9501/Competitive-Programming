/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2007/open07/bronze
Solitario Vacuno/solitair
BFS
*/
#include <map>
#include <queue>
#include <cstdio>
#include <string>

#define oo 1 << 30
using namespace std;
typedef pair<int, int>par;

int n, f, c, nf, nc, C[10][10], A[10][10];
char car, m;
const int mf[] = { -1,  0},
          mc[] = {  0,  1};

queue <par>Q;
string r;
map <string, int>M;

void bfs (){
     Q.push(par(n, 1));
     C[n][1] = A[n][1];
     while (!Q.empty()){
            f = Q.front().first;
            c = Q.front().second;
            Q.pop();
            for (int i = 0; i < 2; i++){
                 nf = f + mf[i];
                 nc = c + mc[i];

                 if (nf > n || nc > n || nf < 1)continue;

                 if (C[nf][nc] < C[f][c]+A[nf][nc]){
                     C[nf][nc] = C[f][c]+A[nf][nc];
                     Q.push(par(nf, nc));
                 }
            }
     }
}

int main(){

    freopen ("solitair.in", "r", stdin);
    freopen ("solitair.out", "w", stdout);

    M["A"] = 1;
    M["T"] = 10;
    M["J"] = 11;
    M["Q"] = 12;
    M["K"] = 13;

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++){
              scanf ("%c", &car);
              scanf ("%c%c", &car, &m);
              r = "";
              r += car;
              if (car >= '1' && car <= '9')
                  A[i][j] = car - '0';
               else
                  A[i][j] = M[r];
         }

    bfs ();

    printf ("%d", C[1][n]);


    return 0;
}
