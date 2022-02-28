/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007/noviembre/oro
Bloqueador/tanning
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int a, b, n, m, sol, x , y;

struct tri{
       int ini, fin, dif;
       bool operator <(const tri &R)
       const {
              if (R.ini != ini)
                  return ini < R.ini;
              return fin < R.fin;
       }
}A[25005];
int B[25005];

int main(){

    freopen ("tanning.in", "r", stdin);
    freopen ("tanning.out", "w", stdout);

    scanf ("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d\n", &A[i].ini, &A[i].fin);
         A[i].dif = A[i].fin - A[i].ini;
    }

    for (int i = 1; i <= m; i++){
         scanf ("%d %d\n", &x, &y);
         B[x] += y;
    }

    sort (A + 1, A + n + 1);
    int r = 1;
    for (int r = 1; r <= n; r++){
         for (int i = r+1; i <= n; i++){
              if (A[r].ini <= A[i+1].ini && A[r].fin >= A[i+1].fin){
                  swap (A[r].ini, A[i+1].ini);
                  swap (A[r].fin, A[i+1].fin);
              }
         }
    }

    for (int i = 1; i <= n; i++){
         for (int j = A[i].ini; j <= A[i].fin; j++){
              if (B[j] > 0){
                  B[j]--;
                  sol++;
                  break;
              }
         }
    }
    //for (int i = 1; i<= n; i++)printf ("%d %d\n", A[i].ini, A[i].fin);
    printf ("%d\n", sol);

    return 0;
}
