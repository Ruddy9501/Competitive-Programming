/*
Ruddy Guerrero Alvraez
Vila Clara -> Caibarien
/USACO/Problems/2007/nov07/Bronze
Exploración/explore
Oredenamiento topologico
*/
#include <cstdio>
#include <algorithm>

#define RAN 50010
using namespace std;

int n, T, s, t, ult, A[RAN];

int comp (const int &a,const int &b){
    return abs(a) < abs(b);
}

int main(){

    //freopen ("explore.in", "r", stdin);
    //freopen ("explore.out", "w", stdout);

    scanf ("%d %d", &T, &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    sort (A + 1, A + n + 1, comp);

    for (int i = 1; i <= n; i++){
         t += abs(ult - A[i]);

         if (t > T)break;

         s++;
         ult = A[i];
    }

    printf ("%d\n", s);

    return 0;
}
