/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2010-2011/octubre/bronce
Contando Canicas/countbead
AD-HOD
*/
#include <cstdio>

using namespace std;

int n, c, s, c1;

main (){
     
     freopen ("countbead.in", "r", stdin);
     freopen ("countbead.out", "w", stdout);
     
     scanf ("%d", &n);
     
     scanf ("%d", &c1);
     for (int i = 2; i <= n; i++){
          scanf ("%d", &c);
          if (c != c1)
              s++;
          c1 = c;              
     }           
     
     printf ("%d\n", s); 
}
