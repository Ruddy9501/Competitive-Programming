/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007-2008/febrero/plata
Lluvia de meteoros/meteor
*/
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mf[4] = {1,-1, 0, 0},
          mc[4] = {0, 0,-1, 1};

struct tres{
       int col, fil, cos;
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

int n, x, y, z, sol, cos, fil, col, newf, newc;
int M[1005][1005];
bool mar, T[1005][1005];
queue <tres>Q;

int main(){

    freopen ("meteor.in", "r", stdin);
    freopen ("meteor.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d %d", &x, &y, &z);
         if (z == 0)
             z = -1;
         if (M[x][y] == 0 || M[x][y] > z)
             M[x][y] = z;
         for (int j = 0; j < 4; j++){
              newf = x + mf[j];
              newc = y + mc[j];
              if (newf < 0 || newc < 0)
                  continue;
              if (M[newf][newc] == 0 || M[newf][newc] > z)
                  M[newf][newc] = z;
         }
    }

    Q.push(tres(0,0,0));
    while (!Q.empty() && mar == false){
           cos = Q.front().cos + 1;
           fil = Q.front().fil;
           col = Q.front().col;
           Q.pop();
           for (int i = 0; i < 4; i++){
                newf = fil + mf[i];
                newc = col + mc[i];
                if (newf < 0 || newc < 0)
                    continue;
                if (M[newf][newc] == 0){
                    sol = cos, mar = true;
                    break;
                }
                if (M[newf][newc] > cos && T[newf][newc] == false){
                    Q.push(tres(cos,newf,newc));
                    T[newf][newc] = true;
                }
           }
    }

    if (sol == 0)
        printf ("-1\n");
     else
        printf ("%d\n", sol);

    return 0;
}
