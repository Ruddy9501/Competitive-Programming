/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Prueba Final #3 PSN 2013
Fotografia photo
*/
#include <cstdio>
#include <algorithm>

#define RAN 5000
using namespace std;

long long F, sol, n, p, a, b, c, j;

struct par{
       long long id, p;
       bool operator <(const par &R)
       const {
             return R.p > p;
       }
}A[RAN];

int main(){

    scanf ("%I64d %I64d", &F, &n);
    for (int i = 1; i <= n; i++){
         scanf ("%I64d %I64d",&a, &b);
         A[++c].p = a;
         A[c].id = i;
         A[++c].p = b;
         A[c].id = i;
    }

    A[++c].p = F;
    A[c].id = -1;

    sort (A + 1, A + c + 1);
    p = 9999999999999;
    for (int i = 1; i <= c; i++){
         for (j = i+1; j <= c && A[i].id != A[j].id; j++);

         p = min (p, j-1);
         if (i == p){
             p = 999999999999;
             sol++;
             continue;
         }
    }

    printf ("%I64d\n", sol);

    return 0;
}
