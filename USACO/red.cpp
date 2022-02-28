/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
EXPLORA #3 PSN 2013
Red Confiable/red
*/
# include <cstdio>
# include <algorithm>

#define RAN 20
#define RAN1 1 << RAN
using namespace std;

int nd, nc, K[RAN], V[RAN][RAN], c, A[RAN], B[RAN], C[RAN], s = 1 << 30;
bool M[RAN], mar, m[RAN1];

void dfs (int nod){
     M[nod] = true;
     for (int i = 1; i <= K[nod]; i++)
          if (!M[V[nod][i]])
              dfs (V[nod][i]);
}

int main (){

    freopen ("red.in", "r", stdin);
    freopen ("red.out", "w", stdout);

    scanf ("%d %d", &nd, &nc);
    for (int i = 0; i < nc; i++)
         scanf ("%d %d %d", &A[i], &B[i], &C[i]);

    for (int i = 1 << (nc-nd); i < (1 << nc); i++){
         if ( __builtin_popcount(i) < nd - 1 ) continue;
         c = 0;
         for (int j = 1; j <= nd; j++)K[j] = 0;

         for (int j = 0; j < nc; j++){
              if (i & (1 << j)){
                  V[A[j]][++K[A[j]]] = B[j];
                  V[B[j]][++K[B[j]]] = A[j];
                  c += C[j];
              }
         }

         if (c > s)continue;
         dfs (1);

         for (int j = 1 ; j <= nd; j++){
              if (M[j] == 0)
                  mar = 1;
              M[j] = 0;/*
              K[j] = 0;*/
         }
         if (mar == 0)
             m[i] = 1;
         mar = 0;

         if (!m[i])continue;
             for (int j = 0; j < nc; j++)
                   if (i & (1 << j))
                   if (!m[i - (1 << j)]){
                       mar = 1;
                       break;
                   }
         if (mar == 0 && s > c)
             s = c;
         mar = 0;
    }

    if (s == 1 << 30)
        s = -1;

    printf ("%d\n", s);

    return 0;
}
