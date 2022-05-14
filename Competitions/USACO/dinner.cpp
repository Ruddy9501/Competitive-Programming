/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Problems/2010-11/October/Problems/Silver
Hora de Cenar/dinner
*/
#include <cstdio>
#include <algorithm>

#define RAN 1010
#define oo 99999999999999999
using namespace std;

int n, m, id, j;
bool M[RAN];
long long X[RAN], Y[RAN], x, y, s;

long long dis(){
     return ((X[j]+RAN)-(x+RAN))*((X[j]+RAN)-(x+RAN))+
            ((Y[j]+RAN)-(y+RAN))*((Y[j]+RAN)-(y+RAN));
}

int main(){

    freopen ("dinner.in", "r", stdin);
    freopen ("dinner.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    if (n == m){printf ("0");return 0;}

    for (int i = 1; i <= n; i++)
         scanf ("%lld %lld", &X[i], &Y[i]);

    for (int i = 1; i <= m; i++){
         scanf ("%lld %lld", &x, &y);
         s = oo;
         for (j = 1; j <= n; j++)
              if (!M[j] && ((X[j]+RAN)-(x+RAN))*((X[j]+RAN)-(x+RAN))+((Y[j]+RAN)-(y+RAN))*((Y[j]+RAN)-(y+RAN)) < s){
                  s = dis();
                  id = j;
              }
         M[id] = 1;
    }

    for (int i = 1; i <= n; i++)
         if (!M[i])
             printf ("%d\n", i);
    return 0;
}
