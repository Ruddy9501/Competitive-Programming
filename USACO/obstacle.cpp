/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/2007-2008/octubre/plata
Camino con Obstáculos/obstacle
BFS
*/
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int mf[4] = { 1, -1,  0, 0},
          mc[4] = { 0,  0, -1, 1};

int n, fil, cos, col, S = 1 << 29, newf, newc, dir, X, Y, C[1000][1000];
char M[1000][1000];
struct tres{
       int fil, col, dir, cos;
       tres (int a = 0, int b = 0, int c = 0, int d = 0){
             fil = a;
             col = b;
             dir = c;
             cos = d;
       }
       bool operator <(const tres &R)
       const{
             return R.cos < cos;
       }
};
queue <tres>Q;

int main(){

    freopen ("obstacle.in", "r", stdin);
    freopen ("obstacle.out", "w", stdout);

    scanf ("%d\n", &n);
    for (int i = 1 ; i <= n; i++){
         for (int j = 1; j <= n; j++){
              scanf ("%c", &M[i][j]);
              if (M[i][j] == 'A')
                  X = i, Y = j;
         C[i][j] = 1 << 29;
         }scanf ("\n");
    }

    C[X][Y] = -1;
    Q.push(tres(X,Y,-1,-1));
    while (!Q.empty()){
           fil = Q.front().fil;
           col = Q.front().col;
           dir = Q.front().dir;
           if (C[fil][col] >= Q.front().cos)
           for (int i = 0; i < 4; i++){
                newf = fil + mf[i];
                newc = col + mc[i];
                cos = Q.front().cos;
                if (i != dir)
                    cos++;
                if (M[newf][newc] == 'B' && S > cos)
                    S = cos;
                if (M[newf][newc] == '.' && C[newf][newc] >= cos){
                    Q.push(tres(newf, newc, i, cos));
                    C[newf][newc] = cos;
                }
           }
           Q.pop();
    }

    printf ("%d\n", S);

    return 0;
}
