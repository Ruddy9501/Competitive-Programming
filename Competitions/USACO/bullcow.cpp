/*
Ruddy Guerrero Alvarez
Villa Clara -- caibarien
USACO\2008\febrero\plata
Toros y Vacas\ bullcow
*/

#include <cstdio>
#include <algorithm>

#define MOD 5000011
#define RAN 100010

using namespace std;

int n, m;
int C[RAN];

main (){

      freopen ("bullcow.in", "r", stdin);
      freopen ("bullcow.out", "w", stdout);
      
      scanf ("%d %d", &n, &m);
      
	  for (int i = 0; i <= n; i++){
	       if (i <= m)
		       C[i] = i + 1;
			else
               C[i] = (C[i-1] + C[i-m-1]) % MOD;			
	  }
	  
      printf ("%d\n", C[n]);
}
