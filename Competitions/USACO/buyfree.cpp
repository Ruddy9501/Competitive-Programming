/*
Ruddy Guerrero Alvarez
Villa Clara -> CAibarien
USACO\Problems\2007\feb07\Bronze
Compre Uno Obtenga Uno Gratis\buyfree
AD-HOD
*/
#include <cstdio>
#include <algorithm>

#define RAN 10010
using namespace std;

int A[RAN], B[RAN], n, m, s, c;

int main(){

    freopen ("buyfree.in", "r", stdin);
    freopen ("buyfree.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    for (int i = 1; i <= m; i++)
         scanf ("%d", &B[i]);

    sort (B+1, B+m+1);
    sort (A+1, A+n+1);

    c = 1;
    for (int i = 1; i <= n; i++){
         if (B[c] >= A[i] || c > m)
             s++;
          else
             c++, s += 2;
    }

    printf ("%d\n", s);

    return 0;
}
