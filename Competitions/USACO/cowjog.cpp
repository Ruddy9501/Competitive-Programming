/*
Ruddy Guerrero Alvarez
Villa Clara -- Caibarien
USACO\2008\marzo\oro
Trote Vacuno\cowjog
K Camino Minimo
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

#define RAN 1010

using namespace std;
typedef pair <int, int>par;

int x, y, z, K, nd, nc, nod, cos, newn, newc; 
vector <par>V[RAN];
priority_queue <par, vector <par>, greater<par> >Q;

main (){
     
      freopen ("cowjog.in", "r", stdin);
      freopen ("cowjog.out", "w", stdout);
      
      scanf ("%d %d %d\n", &nd, &nc, &K);
     
     for (int i = 1; i <= nc; i++){
           scanf ("%d %d %d\n", &x, &y, &z);
           V[x].push_back(par(y, z));
      }
     
      Q.push(par(0, nd));
      while (!Q.empty()){
             nod = Q.top().second;
             cos = Q.top().first;
             Q.pop();
              if (nod == 1){
                  K--;
                  if (K >= 0){
                      printf ("%d\n", cos);
                      continue;  
                  }
                   else
                      return 0;  
              }
             for (int i = 0; i < V[nod].size(); i++){
                  newn = V[nod][i].first;
                  newc = V[nod][i].second + cos;
                  Q.push(par(newc, newn));
             }
      }
      
      while (K > 0){
             printf ("-1\n");
             K--;
      }   
}
