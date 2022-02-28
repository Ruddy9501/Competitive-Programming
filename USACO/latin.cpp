/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/Problems/2007/mar07/mar07_bronze
Latín Bovino/latin
Brute Forse
*/
#include <cstdio>
#include <cstring>

#define RAN 100
using namespace std;

int n, la;
char A[RAN];

int main(){

   // freopen ("latin.in", "r", stdin);
   // freopen ("latin.out", "w", stdout);

    scanf ("%d\n", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%s", A);
         la = strlen (A)-1;
         if (A[0] == 'a' || A[0] == 'e' || A[0] == 'i' || A[0] == 'o' || A[0] == 'u')
             printf ("%scow\n", A);
          else{
             for (int j = 1; j <= la; j++)
                  printf ("%c", A[j]);
             printf ("%cow\n",A[0]);
          }
    }
    return 0;
}
