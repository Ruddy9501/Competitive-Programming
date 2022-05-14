/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2009-10/Marzo/Problems/Bronze
Conversión Hexadecimal/hex
*/
#include <cstdio>
#include <cstring>

#define RAN 100010
using namespace std;

int la, c = -1, s, s1[RAN*3], c1, a[RAN];
char A[RAN];

int main(){

    freopen ("hex.in", "r", stdin);
    freopen ("hex.out", "w", stdout);

    scanf ("%s", &A);
    la = strlen (A)-1;

    for (int i = 0; i <= la; i++)
         if (A[i] >= 'A')
             a[i] = A[i] - 'A'+10;
          else
             a[i] = A[i] - '0';

    for (int i = la; i >= 0; i--){
         for (int j = 0; j < 4; j++){
              c++;
              if (a[i] & (1 << j))
                  s += (1 << c);
              if (c == 2){
                  s1[++c1] = s;
                  s = 0;
                  c = -1;
              }
         }
    }

    s1[++c1] = s;
    while (s1[c1] == 0 && c1 != 1){
           c1--;
    }

    for (int i = c1; i >= 1; i--)
         printf ("%d", s1[i]);

    return 0;
}
