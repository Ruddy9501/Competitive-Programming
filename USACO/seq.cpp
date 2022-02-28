/*
Ruddy Guerrero Alvarez
PSN 2013 Prueba Final #5
Secuencia/seq
Matematico
*/
#include <cmath>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a, s1, n1, s2, t, c;
bool M[1000010];
queue <int>Q;

int main(){

    scanf ("%d", &n);

    if (n == 1){
        printf ("1 2\n");
        return 0;
    }


    s1 = (n/3);
    if (n % 3 != 0)
        s1++;

    printf ("%d", s1);

    t = sqrt(n);
    for (int i = 2;i <= t; i++){
         if (!M[i]){
             for (int j = i+i; j <= n; j+=i)
                  M[j] = 1;
         }

    }

    for (int i = 2; i <= n; i++)
         if (!M[i])Q.push(i);

    n1 = n;
    while (!Q.empty()){
           a = Q.front();
           Q.pop();

           while (n1 % a == 0){
                  n1 = n1 / a;
                  s2++;
           }

           if (a == 2 && s2){
               s2 = ((s2/2)+(s2%2));
           }
    }

    if (s2 == 1)s2++;

    printf (" %d\n", s2);

    return 0;
}
