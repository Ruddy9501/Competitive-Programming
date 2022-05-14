/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2007/mar07/mar07_bronze
Vacas De La Mesa Redonda/round
Recursivo 
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n, T, s, i, can, P[11], A[11], B[11];
bool M[11];

void dfs(int p){
     M[p] = 1;
     can++;
     if (can == n && abs(A[1]-A[p]) <= T)
         s++;
      else
         for (int i = 1; i <= n; i++)
              if (!M[i] && abs(A[i]-A[p]) <= T){
                  dfs (i);
              }
     M[p] = 0;
     can--;
}

int main(){

    freopen ("round.in", "r", stdin);
    freopen ("round.out", "w", stdout);

    scanf ("%d %d", &n, &T);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    dfs (1);

    printf ("%d\n", s);

    return 0;
}
