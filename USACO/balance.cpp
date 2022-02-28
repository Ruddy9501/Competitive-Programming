/*
Ruddy Guerrero Alvarez
USACO MAR07 balance 
*/
#include <cstdio>
#include <algorithm>

#define RAN 50002
using namespace std;

int n;
long long S[RAN*2], sol;

struct par{
       int v;
       long long p;
       bool operator <(const par &R)
       const{
            return R.p > p;
       }
}A[RAN];

int main(){

    freopen ("balance.in", "r", stdin);
    freopen ("balance.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d %lld", &A[i].v, &A[i].p);

    sort (A + 1, A + n + 1);
    int pos = 50000;
    for (int i = 1, s; i <= n; i++){
         if (S[pos] == 0)
             S[pos] = A[i].p;

         if (A[i]. v == 0)
             pos++;
          else pos--;

         if (S[pos] != 0)
             sol = max (sol, A[i].p - S[pos]);
    }

    printf ("%lld\n", sol);

    return 0;
}
