/*
Ruddy Guerrero ALvarez
12mo
Villa CLara -> Caibarien
USACO/Problems/2009-10/Abril/Problems/Bronze
Vacas Parceras/cowpals
Bruete Forse
*/
#include <cstdio>

using namespace std;

int n, a, b, s;

int sum(int a){
    s = 0;
    for (int i = 1; i*i <= a; i++){
         if (a % i == 0){
             s += i;
             if (a / i != i)
                 s += (a/i);
         }
    }
    return s;
}

int main(){

    freopen ("cowpals.in", "r", stdin);
    freopen ("cowpals.out", "w", stdout);

    scanf ("%d", &n);
    for ( ; ; n++){
         a = sum (n)-n;
         b = sum (a)-a;
         if (b == n && n != a){
             printf ("%d %d\n", n, a);
             break;
         }
    }

    return 0;
}
