/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/2008-2009/diciembre/oro
Triqui Triqui en la Granja/treat
*/
#include <cstdio>

#define RAN 100005
using namespace std;

int n, r, A[RAN], can, can1, k, Td[RAN], nod, S[RAN];

int main(){

    freopen ("TREAT.in", "r", stdin);
    freopen ("TREAT.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    for (int i = 1; i <= n; i++){
         can = 0;
         nod = i;
         if (!Td[nod]){
             ++k;
             while (!Td[nod]){
                    Td[nod] = k;
                    can++;
                    nod = A[nod];
             }
             if (Td[nod] != k)
                 can += S[nod];
             r = i;
             while (r != nod){
                    S[r] = can;
                    can--;
                    r = A[r];
             }
             if (Td[nod] == k){
                 S[nod] = can;
                 r = A[nod];
                 while (r != nod){
                        S[r] = can;
                        r = A[r];
                 }
             }
         }
    }

    for (int i = 1; i <= n; i++)
         printf ("%d\n", S[i]);

    return 0;
}
