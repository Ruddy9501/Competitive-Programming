/*
Ruddy Guerrero Alvarez
Caibarien--Villa Clara--Cuba
Charcos  de Lodo\mud\USACO\plata\
diciembre\2007\BFS para matriz
*/
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int mf[4] = {0, 0,-1, 1},
          mc[4] = {1,-1, 0, 0};

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

int cos, nf, nc,f, c, x, y, X, Y, N;
bool M[1001][1001];
queue <tres>Q;

int main(){

    freopen ("mud.in","r",stdin);
    freopen ("mud.out","w",stdout);

    scanf ("%d %d %d\n",&X, &Y, &N);
    X += 500;
    Y += 500;

    for (int i = 1; i <= N; i++){
         scanf ("%d %d\n", &x, &y);
         M[x+500][y+500] = true;
    }

    M[500][500] = true;
    Q.push(tres(0, 500, 500));
    while (!Q.empty()){
           cos = Q.front().cos;
           f = Q.front().fil;
           c = Q.front().col;
           Q.pop();
           for (int i = 0; i < 4; i++){
                nf = mf[i] + f;
                nc = mc[i] + c;
                if (M[nf][nc] == false){
                    M[nf][nc] = true;
                    if (nf == X && nc == Y){
                        printf ("%d\n",cos+1);
                        return 0;
                    }
                    Q.push(tres(cos+1, nf, nc));
                }
           }
    }

    return 0;
}
