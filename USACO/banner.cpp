/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2010-11\November\Problems\Silver
Pancarta\banner
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int nf, nc, a, b, dis;
long long s;

int gsd(int a, int b){

    while (a){
           swap(a, b);
           a %= b;
    }

    return b;
}

int main(){

    freopen ("banner.in", "r", stdin);
    freopen ("banner.out", "w", stdout);

    scanf ("%d %d %d %d", &nf, &nc, &a, &b);

    if (a == 1)s = nf*(nc+1) + nc*(nf+1);

    for (int i = 1; i <= nf; i++)
         for (int j = 1; j <= nc; j++){
              dis = i*i + j*j;

              if (dis < a*a || dis > b*b)continue;

              if (gsd(i, j) != 1)continue;

              s += (nf-i+1)*(nc-j+1)*2;

         }

    printf ("%lld\n", s);

    return 0;
}
