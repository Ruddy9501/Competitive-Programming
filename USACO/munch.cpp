/*
Ruddy Guerrero 
12mo
Villa Clara -> Caibarien
*/
#include <queue>
#include <cstdio>
#include <cstring>

#define oo 1 << 30
#define RAN 105
using namespace std;

const int mf[5] = {  0,  0,  1, -1},
          mc[5] = { -1,  1,  0,  0};

struct tri{
       int fil, col, cos;
       tri (int a = 0, int b = 0, int c = 0){
            cos= a;
            fil = b;
            col = c;
       }
       bool operator <(const tri &R)
       const {
              return R.cos < cos;
       }
};

int f, c, ff, fc, ii, ic, nf, nc, F, C, cos;
int C1[RAN][RAN];
char A[RAN][RAN];
priority_queue <tri>Q;

int main(){

    freopen ("munch.in", "r", stdin);
    freopen ("munch.out", "w", stdout);

    scanf ("%d %d\n", &F, &C);
    for (int i = 1; i <= F; i++){
         for (int j = 1; j <= C; j++){
              scanf ("%c", &A[i][j]);
              C1[i][j] = oo;
              if (A[i][j] == 'C')
                  ff = i, fc = j;
               else
                  if (A[i][j] == 'B')
                      ii  = i, ic = j;
         }
         scanf ("\n");
    }

    C1[ii][ic] = 0;
    Q.push(tri(0, ii, ic));
    while (!Q.empty()){
           f = Q.top().fil;
           c = Q.top().col;
           cos = Q.top().cos;
           Q.pop();
           for (int i = 0; i < 4; i++){
                nf = mf[i] + f;
                nc = mc[i] + c;
                if ((A[nf][nc] == '.' || A[nf][nc] == 'C') && C1[nf][nc] > cos+1){
                    C1[nf][nc] = cos+1;
                    Q.push(tri(cos+1, nf, nc));
                }
           }
    }

    printf ("%d\n", C1[ff][fc]);

    return 0;
}
