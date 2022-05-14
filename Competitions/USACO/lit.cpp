/*
Ruddy guerrero Alvarez
Villa Clara -> Caibarien
Intercambiando letras/lit
AD-Hod
*/
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

#define RAN 1000010
using namespace std;

int n, r, res, con, c, A[RAN], B[RAN], R[RAN], C[30];
char car;
long long s;

vector <int>V[30];

struct par{
       int p, pm;
       bool operator <(const par &R)
       const{
            return R.p > p;
       }
}S[RAN];

int main(){

    freopen ("lit.in", "r", stdin);
    freopen ("lit.out", "w", stdout);

    scanf ("%d\n", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%c", &car);
         A[i] = car - 'A';
         V[A[i]].push_back(i);
    }

    scanf ("\n");
    for (int i = 1; i <= n; i++){
         scanf ("%c", &car);
         B[i] = car - 'A';
         S[++c].p = V[B[i]][C[B[i]]];
         C[B[i]]++;
         S[c].pm = i;
    }

    sort (S + 1, S + c + 1);

    for (int i = 1; i <= c; i++){
         r = 0;
         for (int j = abs(S[i].pm); j >= 1; j -= (j & -j))
              r += R[j];
         s = s + abs(S[i].pm - S[i].p + con - r);
         con++;
         for (int j = abs(S[i].pm); j <= n; j += (j & -j))
              R[j] += 1;
    }

    printf ("%lld\n", s);

    return 0;
}
