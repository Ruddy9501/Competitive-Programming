/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007/febrero/plata
Lexicon Vacuno/lexicon
Dinamica
*/
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define RAN 1005
using namespace std;
//typedef pair<int, int>par;
struct tres{
       int ini, fin, tb;
       tres (int a = 0, int b = 0, int c = 0){
             fin = a;
             ini = b;
             tb = c;
       }
       bool operator <(const tres &R)
       const {
              return R.fin < fin;
       }
};
int ta, tb, t, c, n, ini, S[RAN], fin;
char A[RAN], B[RAN];
priority_queue <tres>Q;

int main(){

    freopen ("adn.in", "r", stdin);
    freopen ("adn.out", "w", stdout);

    scanf ("%d\n", &t);
    scanf ("%s\n", A+1);
    ta = strlen(A+1);
    for (int i = 1; i <= t; i++){
         scanf ("%s", B+1);
         tb = strlen (B+1);
         c = 1;
         for (int j = 1; j <= ta; j++){
              if (B[1] == A[j]){
                  c = 2;
                  for (int k = j+1; k <= ta; k++){
                       if (B[c] == A[k]){
                           c++;
                           if (c == tb+1){
                               Q.push(tres(k, j, tb));
                               break;
                           }
                       }
                       else
                        break;
                  }
              }
         }
    }

    for (int i = 1; i <= ta; i++){
        S[i] = S[i-1];
         while (Q.top().fin == i && !Q.empty()){
                fin = Q.top().fin;
                ini = Q.top().ini;
                S[i] = max (S[i], S[ini-1]+1);
                Q.pop();
        }
    }

    printf ("%d\n", S[ta]);

    return 0;
}
