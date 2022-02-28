/*
Ruddy Guerrero Alvarez
Caibarien--Villa Clara
Rueda de la Fortuna\colo\
PSN\THAILAND\2011
Brute Forse
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

#define RAN 27
#define MAX 100
using namespace std;

int n, m, a, p;
int A[MAX];
char C[RAN], b;
bool M[MAX];

int main(){

    freopen ("KOLO.in","r",stdin);
    freopen ("KOLO.out","w",stdout);

    scanf ("%d %d\n", &n, &m);

    p = 0;
    for (int i = 1; i <= m; i++){
         scanf ("%d %c\n", &a, &b);
         p = (p + a) % n;
         if (p == 0)
             p = n;
         if (C[p] == '\0' || C[p] == b){
             C[p] = b;
             if ( M[b] == true){
                 if (A[b] != p){
                     printf ("!\n");
                     return 0;
                 }
             }
             else{
                 M[b] = true;
                 A[b] = p;
             }
         }
          else{
             printf ("!\n");
             return 0;
         }
    }

    reverse (C + 1, C + p + 1);
    reverse (C + p + 1, C + n + 1);

    for (int i = 1; i <= n; i++){
         if (C[i] == '\0')
             printf ("?");
          else
             printf ("%c",C[i]);
    }

    printf ("\n");

    return 0;
}
