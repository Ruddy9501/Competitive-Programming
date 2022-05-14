/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007-2008/febrero/bronce
Profesor de Matemáticas Cruel II/cruel II
Busqueda binaria
*/
#include <cstdio>
#include <algorithm>

using namespace std;

double p, sum, r, A[200], ini, fin, n;

double R(double p){
       sum = A[1];
       r = 1;
       for (int i = 2; i <= n+1; i++){
            r *= p;
            sum += (A[i]*r);
       }
       return sum;
}

int main(){

    freopen ("cruel2.in", "r", stdin);
    freopen ("cruel2.out", "w", stdout);

    scanf ("%llf", &n);
    for (int i = 1; i <= n+1; i++){
         scanf ("%llf", &A[i]);
    }

    ini = -1000;
    fin = 1000;
    while (ini+(0.00005) <= fin){
           p = (double)(ini + fin) / 2;
           double s = R(p);
           if (R(ini) > R(fin)){
               if (s < 0)
                   fin = p;
                else
                   ini = p;
           }
           else{
               if (s > 0)
                   fin = p;
                else
                   ini = p;
           }
    }

     printf ("%d", int(p*1000));

    return 0;
}
