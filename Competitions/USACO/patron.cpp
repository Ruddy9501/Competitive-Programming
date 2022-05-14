/*
Ruddy Guerrero Alvarez
12mo
NACIONAL 2009 DIA 1
PRE-KMP
*/
#include <cstdio>
#include <cstring>

int n, k, ocu[20000005];
char A[20000005];

using namespace std;

int main(){

    freopen ("patron.in", "r", stdin);
    freopen ("patron.out", "w", stdout);

    scanf ("%d", &n);
    scanf ("%s", A + 1);

    for (int i = 2; i <= n; i++){
         while (A[k+1] != A[i] && k > 0)
                k = ocu[k];
         if (A[k+1] == A[i])
             k++;
         ocu[i] = k;
    }

    printf ("%d\n", n-ocu[n]);

    return 0;
}