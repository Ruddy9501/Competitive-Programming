#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, t, c;
long long sol;

int main (){

    freopen ("secpas.in", "r", stdin);
    freopen ("secpas.out", "w", stdout);

    scanf ("%d\n", &n);

    t = sqrt(n);
    for (int i = 0; i <= t; i++)
         for (int j = 0; j <= t && ((i*i)+(j*j)) <= n; j++)
             for (int k = 0; k <= t && ((i*i)+(j*j)+(k*k)) <= n; k++)
                  for (int l = 0; l <= t && ((i*i)+(j*j)+(k*k)+(l*l)) <= n; l++){
                       if (i*i+j*j+k*k+l*l == n)
                            sol++;
                  }

    printf ("%lld",sol);
    return 0;
}
