/*
Ruddy Guerrero Alvarez
VILLA CLARA -> CAIBARIEN
PSN 2013 PRUEBA EXPLORTORIA #2
AD-HOD
La mayor secuencia/sequence                                                      
*/
#include <cstdio>
#include <algorithm>

#define RAN 100005
using namespace std;

int n, m, a, sol, s, ult, A[RAN];
bool mar, M[RAN];

int main(){

    freopen ("sequence.in", "r", stdin);
    freopen ("sequence.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%d", &a);
         if (a == 0)mar = true;
         M[a] = true;
    }
    sol = 0;
    for (int i = 1; i <= n; i++){
         if (M[i] == 1)
             sol++;
          else{
             if (mar == true){
                 sol = sol - A[ult] + 1;
                 ult = i;
             }
             else
                 sol = 0;
          }
          if (sol > s)
              s = sol;
          A[i] = sol;
    }

    printf ("%d\n", s);

    return 0;
}
