/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/octubre/bronce
Huesos Bovinos/bones
brute force -> tonta
*/
#include <cstdio>

#define RAN 100
using namespace std;

int a, b, c, m, s, S[RAN];

int main(){

   // freopen ("bones.in", "r", stdin);
    //freopen ("bones.out", "w", stdout);

    scanf ("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= a; i++)
         for (int j = 1; j <= b; j++)
              for (int k = 1; k <= c; k++)
                   S[i+j+k]++;

    for (int i = 1; i <= a+b+c; i++)
         if (m < S[i]){
             m = S[i];
             s = i;
         }

    printf ("%d\n", s);

    return 0;
}
