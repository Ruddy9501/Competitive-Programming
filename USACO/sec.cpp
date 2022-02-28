/*
Ruddy Guererro Alvarez
Villa Clara -- Caibarien
USACO\2008\diciembre\oro
Mensaje Secreto\sec
*/
#include <cstdio>
#include <algorithm>

#define RAN 5

using namespace std;

struct trie{
       trie *arb[RAN];
       int mar, r;
}*P, TRIE;
 
int n, m, t, d, car, sol;

main (){

      freopen ("sec.in", "r", stdin);
      freopen ("sec.out", "w", stdout);
      
      scanf ("%d %d\n", &n, &m);
      
      for (int i = 1; i <= n; i++){
           scanf ("%d", &t);
           P = &TRIE;
           for (int j = 1; j <= t; j++){
                scanf ("%d", &car);
                if (P -> arb[car] == NULL)
                    P -> arb[car] = new trie();
                 P = P -> arb[car];
                 P -> r++;;
           }
           P -> mar++;
      }
      
      for (int i = 1; i <= m; i++){
           scanf ("%d", &t);
           P = &TRIE;
           sol = 0;
           for (int j = 1; j <= t; j++){
               scanf ("%d", &car);
                
                if (P == NULL)continue;
                sol += P -> mar;
                P = P -> arb[car];
           }
           if (P != NULL)
               sol += P -> r;
           printf ("%d\n", sol);
                 
      }
}
