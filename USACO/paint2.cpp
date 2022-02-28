/*
Ruddy Guerrero Alvarez
12mo
USACO/2007-2008/octubre/oro/
Super Paintball/paint2
AD-Hod
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, f, c, sol;
int F[105], C[105], D1[2*105], D2[2*105], M[105][105];

int main(){

    freopen ("paint2.in", "r", stdin);
    freopen ("paint2.out", "w", stdout);

    scanf ("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%d %d\n", &f, &c);
         F[f]++;
         C[c]++;
         D1[f+c]++;
         D2[f-c+n]++;
         M[f][c]++;
    }

    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= n; j++){
              if (m == F[i] + C[j] + D1[i+j] + D2[i-j+n] - 3*M[i][j])
                  sol++;
         }
    }

    printf ("%d\n", sol);

    return 0;
}
