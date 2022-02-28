/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
/USACO/Problems/2007/oct07/bronze
Vacas Privilegiadas/privc
AD-HOD
*/
#include <cstdio>

#define RAN 1010
using namespace std;

int n, u, d, t, d1, t1, s, A[RAN];

int main(){

    //freopen ("privc.in", "r", stdin);
    //freopen ("privc.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         switch (A[i]){
                 case 1 : {u++; break;}
                 case 2 : {d++; break;}
                 case 3 : {t++; break;}
         }
    }

    d1 = u+1;
    t1 = n;
    for (int i = 1; i <= u; i++){

         if (A[i] == 2){
             s++;
             for ( ; d1 <= n; d1++)
                  if (A[d1] == 1){
                      A[d1] = 2;
                      break;
                  }
         }

         if (A[i] == 3){
             s++;
             for ( ; t1 >= u+1; t1--)
                  if (A[t1] == 1){
                      A[t1] = 3;
                      break;
                  }
         }
    }

    for (int i = u+1; i <= u+d; i++)
         if (A[i] != 2)
             s++;

    printf ("%d\n", s);

    return 0;
}
