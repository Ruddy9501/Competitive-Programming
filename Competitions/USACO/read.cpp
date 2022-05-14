/*
Ruddy Guerrero Alvraez
Vila Clara -> Caibarien
/USACO/Problems/2007/nov07/Bronze
Lectura Veloz/read
Ad-Hod
*/

#include <cstdio>

using namespace std;

int n, a, b ,c, P, m, s;

int main(){

    //freopen ("read.in", "r", stdin);
    //freopen ("read.out", "w", stdout);

    scanf ("%d %d", &P, &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d %d", &a, &b, &c);
         s = P/a+(P%a>=1);
         m = P/a/b;
         if (P%a==0 && (P/a)%b==0)
             m--;
         printf ("%d\n", s+m*c);
    }

    return 0;
}
