/*
Ruddy Guerrero Alvarez
Villa Clara -- Caibarien
USACO\2008\diciembre\plata
Palmeando Cabezas\patheads
AD-HOD
*/
#include <cstdio>
#include <algorithm>

const int RAN = 1000100;

using namespace std;

int n, MAX;
int A[RAN], B[RAN], M[RAN];

main (){
     
      freopen ("patheads.in", "r", stdin);
      freopen ("patheads.out", "w", stdout);
      
      scanf ("%d\n", &n);     
      
      for (int i = 1; i <= n; i++){
           scanf ("%d\n", &M[i]);
           A[M[i]]++;
           if (M[i] > MAX)
               MAX = M[i]; 
      }
      
      for (int i = 1; i <= MAX; i++){
           if (A[i] == 0)continue;
           for (int j = i; j <= MAX; j += i)
                B[j] += A[i];
           B[i]--;
      }
      
      for (int i = 1; i <= n; i++)
           printf ("%d\n", B[M[i]]);
}
