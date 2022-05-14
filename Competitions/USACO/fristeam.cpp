/*
Ruddy Guerrero Alvarez
Villa Clara -- Caibarien
USACO\2008\marzo\plata
Counting Change 
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 1010
#define MOD 100000000

using namespace std;
typedef pair<int, int>par;

int n, m, T, cos;
int C[RAN];
bool M[RAN];
queue <par>Q;

main (){
     
     freopen ("fristeam.in","r",stdin);
     freopen ("fristeam.out","w",stdout);
     
     scanf ("%d %d\n", &n, &T);
     
     M[0] = true;
     C[0] = 1;
     for (int i = 1; i <= n; i++){
          scanf ("%d\n", &m);
          if (m % T != 0)
              m %= T;
           else
              m = T;
          for (int j = T; j >= 0; j--){
               if (M[j] == true){
                   if (j + m > T)
                       Q.push(par(j + m, C[j]));
                    else
                       M[j + m] = true,
                       C[j + m] = (C[j + m]+ C[j]) % MOD;
               }
          }
          while (!Q.empty()){
                 m = Q.front().first;
                 if (m % T != 0)
                     m %= T;
                  else
                     m = T;   
                 cos = Q.front().second;
                 C[m] = (C[m] + cos) % MOD;
                 Q.pop();
                 M[m] = true;
          }
     }
     
     printf ("%d\n", C[T]);
     }
