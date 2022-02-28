/*
Ruddy Guerrero Alvarez
Caibarien--Villa Clara
USACO\2008\enero\bronce
iCow\icow
Brute Force
*/
#include <cstdio>
#include <algorithm>
#define RAN 1002
using namespace std;

int id, id1, n, m, may, s, sum;
int A[RAN];

int main(){

    freopen ("icow.in","r",stdin);
    freopen ("icow.out","w",stdout);

    scanf ("%d %d\n", &n, &m);

    for (int i = 1; i <= n; i++){
         scanf ("%d\n", &A[i]);
         if (A[i] > may){
             may = A[i];
             id = i;
         }
    }

    for (int i = 1; i <= m; i++){
         sum = A[id] / (n-1);
         s = A[id] % (n-1);
         id1 = id;
         for (int j = 1; j <= s; j++){
              if (j != id1)
                  A[j]++;
               else
                  s++;
         }
         may = 0;
         for (int j = 1; j <= n; j++){
              if (id1 != j){
                  A[j] += sum;
                  if (A[j] > may){
                      may = A[j];
                      id = j;
                  }
              }
         }
         A[id1] = 0;
         printf ("%d\n", id1);

    }

    return 0;
}
