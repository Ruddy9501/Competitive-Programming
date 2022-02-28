/*
Ruddy Guerrero Alvarez
PSN 2010 Prueba final #10
Numero descodificado/decode
*/
#include <cstdio>
#include <cstring>

using namespace std;

int sum, ta;
long long n, n1;
char S[20];

int main(){

    freopen ("decode.in", "r", stdin);
    freopen ("decode.out", "w", stdout);

    scanf ("%lld", &n);
    n1 = n;
    for (int i = n; i >= 1; i--){
         n1--;
         sprintf (S, "%d", n1);
         ta = strlen (S);
         sum = 0;
         for (int j = 0; j < ta; j++)
              sum += S[j]-'0';
         if (n1+sum == n){
             printf ("%lld\n", n1);
             return 0;
         }
    }

    return 0;
}
