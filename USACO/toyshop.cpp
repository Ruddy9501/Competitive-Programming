/*
Ruddy Guerrero ALvarez
12mo
Villa CLara -> Caibarien
/USACO/Problems/2009-10/Febrero/Problems/Bronze
Compra de Juguetes/toyshop
Bruete Forse
*/
#include <cstdio>
#include <algorithm>

#define RAN 25010
using namespace std;

int n;
double a, B[RAN];

struct par{
       int id;
       double c;
       bool operator < (const par &R)
       const {
              return R.c < c;
       }
}A[RAN];

int main(){

    freopen ("toyshop.in", "r", stdin);
    freopen ("toyshop.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &B[i]);
         A[i].c = (double)a/(double)B[i];
         A[i].id = i;
    }

    sort (A + 1, A + n + 1);

    printf ("%d\n", B[A[1].id]+B[A[2].id]+B[A[3].id]);
    printf ("%d\n", A[1].id);
    printf ("%d\n", A[2].id);
    printf ("%d\n", A[3].id);

    return 0;
}
