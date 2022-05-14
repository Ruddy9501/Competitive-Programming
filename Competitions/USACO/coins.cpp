#include <cstdio>

using namespace std;

int k, l, n, M[2][1000003];

int main(){

    freopen ("coins.in", "r", stdin);
    freopen ("coins.out", "w", stdout);



    scanf ("%d %d %d", &k, &l, &n);
    M[1][0] = 1;
    for (int i = 1; i <= 1000002; i++){
         if (M[1][i-1] == 1 || (M[1][i-k] == 1 && i-k >= 0)|| (M[1][i-l] == 1 && i-l >= 0))
             M[0][i] = 1;
          else
             M[1][i] = 1;
    }

    for (int i = 1, a; i <= n; i++){
         scanf ("%d", &a);
         if (M[0][a])
             printf ("A");
          else printf ("B");
    }

    printf ("\n");
    return 0;
}
