/*
VC1 -> Ruddy Guerrero Alvarez
Provincial - 2012-2013
IPVCE "Ernesto Guevara"
12mo
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int A[1000], n, m, cn, cm, c;

int main(){

    freopen ("FIESTA.in", "r", stdin);
    freopen ("FIESTA.out", "w", stdout);

    scanf ("%d%d",&n,&m);
    if (n >= m && (n != m || n % 2 != 1 || n == 1)){
        while (n > 0 || m > 0){
               if (m == 0){
                   n--;
                   A[++c] = 1;
                   continue;
               }
               if (cn < 2 && n > 0){
                   cn++;
                   A[++c] = 1;
                   n--;
                   if (cn == 2 || n == 0)
                       cm = 0;
                   }
                else{
                   cm++;
                   m--;
                   A[++c] = 0;
                   if (cm == 2 || m == 0)
                       cn = 0;
                }

        }
        for (int i = 1; i <= c; i++)
             printf ("%d", A[i]);
        printf ("\n");
    }
     else
       printf ("NO\n");

    scanf ("%d%d",&n,&m);
    c = 0;
    cn = 0;
    cm = 0;
    if (n >= m && (n != m || n % 2 != 1 || n == 1)){
        while (n > 0 || m > 0){
               if (m == 0){
                   n--;
                   A[++c] = 1;
                   continue;
               }
               if (cn < 2 && n > 0){
                   cn++;
                   A[++c] = 1;
                   n--;
                   if (cn == 2 || n == 0)
                       cm = 0;
                   }
                else{
                   cm++;
                   m--;
                   A[++c] = 0;
                   if (cm == 2 || m == 0)
                       cn = 0;
                }

        }
        for (int i = 1; i <= c; i++)
             printf ("%d", A[i]);
        printf ("\n");
    }
     else
       printf ("NO\n");
    return 0;
}
