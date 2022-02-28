/*
Ruddy Guerrero Alvarez
Villa Clara-Caibarien
USACO/octubre/2007-2008/plata
Pastizal Secreto de Bessie/secpas
EL NEGRO ES FRUTABOMBA
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 400
using namespace std;
const int mf[4] = {1, -1, 0,  0},
          mc[4] = {0,  0, 1, -1};
struct tres{
       int cos, fil, col;
       tres(int a = 0, int b = 0, int c = 0){
            cos = a;
            fil = b;
            col = c;
       }
       bool operator <(const tres &R)
       const{
             return R.cos < cos;
       }
};

struct dos{
       int fil, col;
};

int newf, newc, fil, col, cos, S = 1 << 29, F, c, X, Y, f;
int C[RAN][RAN];
char M[RAN][RAN];
bool M1[RAN];
queue <tres>Q;
dos D[RAN], D1[RAN];

int main(){

    freopen ("cornmaze.in", "r", stdin);
    freopen ("cornmaze.out", "w", stdout);

    scanf ("%d %d\n", &F, &c);
    for (int i = 1; i <= F; i++){
         for (int j = 1; j <= c; j++){
              scanf ("%c", &M[i][j]);
              if (M[i][j] == '@')
                  X = i, Y = j;
              if (M[i][j] >= 'A' && M[i][j] <= 'Z'){
                  if (M1[M[i][j]] == false){
                      D[M[i][j]].fil = i, D[M[i][j]].col = j;
                      M1[M[i][j]] = true;
                  }
                   else
                      D1[M[i][j]].fil = i, D1[M[i][j]].col = j;
              }
              C[i][j] = 1 << 29;
         }scanf ("\n");
    }

    Q.push(tres(0,X,Y));
    while (!Q.empty()){
           fil = Q.front().fil;
           col = Q.front().col;
           cos = Q.front().cos;
           Q.pop();
           for (int i = 0; i < 4; i++){
                newf = fil + mf[i];
                newc = col + mc[i];
                if (M[newf][newc] == '=' && S > cos+1)
                    S = cos+1;
                if (M[newf][newc] >= 'A' && M[newf][newc] <= 'Z'){
                    if (newf == D[M[newf][newc]].fil && newc == D[M[newf][newc]].col){
                        f = D1[M[newf][newc]].fil;
                        c = D1[M[newf][newc]].col;
                    }
                     else{
                        f = D[M[newf][newc]].fil;
                        c = D[M[newf][newc]].col;
                     }
                     M[newf][newc] = '#';
                     Q.push(tres(cos+1, f, c));
                     C[f][c] = cos+1;
                }
                if (M[newf][newc] == '.' && C[newf][newc] > cos+1){
                    Q.push(tres(cos+1, newf, newc));
                    C[newf][newc] = cos+1;
                }
           }
    }

    printf ("%d\n", S);

    return 0;
}
