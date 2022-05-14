/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Secuencia de elementos buenos/DOBRI
dinamica
*/
#include <cstdio>

#define RAN 5010
#define S 200010
using namespace std;

int n, s, A[RAN];
int mar, M[1000000];

int main(){

    //freopen ("DOBRI.in", "r", stdin);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
    }

    for (int i = 1; i <= n; i++){
         mar = 0;
         for (int j = i-1; j >= 1; j--){
              if (!M[A[i]+A[j]+S])
                  M[A[i]+A[j]+S] = i;
              if (M[A[i]-A[j]+S] && M[A[i]-A[j]+S] != i && mar == 0){
                  mar = 1;
                  s++;
              }
         }
         if (!M[A[i]+A[i]+S])
              M[A[i]+A[i]+S] = i;
    }

    printf ("%d\n", s);

    return 0;
}
