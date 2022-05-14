/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/noviembre/bronce
Cambiando Luces/swtch
AD - HOD
*/
#include <cstdio>

#define RAN 505
using namespace std;

int n, m, c, a, b, sol, sum, A[RAN], R[RAN], S[RAN];

int main(){

    //freopen ("swtch.in", "r", stdin);
    //freopen ("swtch.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%d %d %d", &c, &a, &b);
         if (c == 0){
             S[a]++;
             R[b+1]++;
         }
          else{
             for (int j = 1; j <= n; j++){
                  sum += S[j] - R[j];
                  A[j] += sum;
                  S[j] = R[j] = 0;
                  A[j] %= 2;
                  if (j >= a && j <= b && A[j] == 1)
                      sol++;

             }
             printf ("%d\n", sol);
             sol = sum = 0;
          }
    }

    return 0;
}
