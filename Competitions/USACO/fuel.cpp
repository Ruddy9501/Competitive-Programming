/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Prueba Final #3 PSN 2013
este ejerciicio esta muy bueno 
Economia del combustible fuel
*/
#include <cstdio>
#include <queue>
#include <algorithm>

#define RAN 100010
using namespace std;

long long n, T, c, F, gas, sol, dis;
long long C[RAN], G[RAN], P[RAN];

struct par{
       long long p, v;
       bool operator <(const par &R)
       const{
             return R.p > p;
       }
}A[RAN];

int main (){

    //freopen ("fuel.in", "r", stdin);

    scanf ("%I64d %I64d %I64d %I64d", &n, &T, &c, &F);
    for (int i = 1; i <= n; i++)
         scanf ("%I64d %I64d", &A[i].p, &A[i].v);

    A[++n].p = F;
    A[n].v = 0;

    sort (A + 1, A + n + 1);

    long long ini = 50001, fin = 50001;
    C[ini] = 0;
    G[ini] = c;
    P[ini] = 0;
    long long rr = c;
    for (int i = 1; i <= n; i++){
         dis = A[i].p - P[fin];
         //gas = G[ini];
         gas = 0;
         while (gas < dis){
                if (gas + G[ini] <= dis){
                    gas += G[ini];
                    sol += C[ini]*G[ini];
                    ini--;
                }
                else{
                    G[ini] -= (dis-gas);
                    sol += C[ini]*(dis-gas);
                    gas = dis;
                }
                if (ini < fin){
                    printf ("-1\n");
                    return 0;
                }
         }

         while (A[i].v <= C[fin] && ini >= fin){
                gas += G[fin];
                fin++;
         }

         if (ini < fin){
             ini = 50001, fin = 50001;
             C[ini] = A[i].v;
             G[ini] = T;
             P[ini] = A[i].p;
         }
         else{
              fin--;
              C[fin] = A[i].v;
              G[fin] = T-(rr-gas);
              rr = T;
              P[fin] = A[i].p;
         }
    }

    printf ("%I64d\n", sol);

    return 0;
}
