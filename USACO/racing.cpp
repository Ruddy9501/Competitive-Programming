/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008/feb08/bronze
Carrera de Larga Distancia/racing
Ad-Hod
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

#define RAN 100010
using namespace std;

int T, n, u, f, d, a, b, s;
char car;

int main(){

    freopen ("racing.in", "r", stdin);
    freopen ("racing.out", "w", stdout);

    scanf ("%d %d %d %d %d\n", &T, &n, &u, &f, &d);
    for (int i = 1; i <= n; i++){
         scanf ("%c\n", &car);
         if (car == 'u')
             a += u, b += d;
         else
            if (car == 'f')
                a += f, b += f;
             else
                a += d, b += u;
         if (T >= a+b)
                 s = i;
    }

    printf ("%d\n", s);

    return 0;
}
