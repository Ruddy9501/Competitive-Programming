/*#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

#define RAN1 50005
#define RAN2 1000005
using namespace std;

int n, con, ini, fin, T[RAN2], A[RAN1], S[RAN2], R[RAN2], P[RAN1];
queue <int>Q;
vector <int>Vs[RAN2], Vr[RAN2];

int main(){

    freopen ("reserve.in", "r", stdin);
    freopen ("reserve.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &ini, &fin);
         S[ini] += 1;
         R[fin+1] += 1;
         Vs[ini].push_back(i);
         Vr[fin+1].push_back(i);
    }

    for (int i = 1; i <= n; i++){
         T[i] = T[i-1] + S[i] + R[i];
         if (R[i] > 0){
             for (int j = 0; j < Vr[i].size(); j++)
                  Q.push(Vr[i][j]);
         }
         if (S[i] > 0){
             for (int j = 0; j < Vs[i].size(); j++){
                  if (Q.empty())
                      P[Vs[i][j]] = ++con;
                   else{
                      P[Vs[i][j]] = P[Q.front()];
                      Q.pop();
                   }
             }
         }
    }

    printf ("%d\n", con);
    for (int j = 1; j <= n; j++)
         printf ("%d\n", P[j]);

    return 0;
}*/
/*
Ruddy Guerrero Alvarez
12mo VC1
IPVCE Ernesto Guevara
Villa Clara -> Caibarien
USACO/2006/plata/febrero/
Reservaciones de Puestos/reserve
*/
#include <cstdio>
#include <queue>
#include <algorithm>


#define RAN1 50005
#define RAN2 1000005
using namespace std;

int n, a, b, f, i, con;
int A[RAN1], P[RAN2];
queue <int>Q;

struct dos{
       int id, val;
       bool operator <(const dos &R)
       const {
              return R.val > val;
       }
}F[RAN1], I[RAN1];

int main (){

    freopen ("reserve.in", "r", stdin);
    freopen ("reserve.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         I[i].id = i;
         I[i].val = a;
         F[i].id = i;
         F[i].val = b;
    }

    sort (I + 1, I + n + 1);
    sort (F + 1, F + n + 1);
    f = i = 1;
    while (i <= n){
           if (I[i].val > F[f].val){
               Q.push(F[f].id);
               f++;
           }
            else{
                if (!Q.empty()){
                    P[I[i].id] = P[Q.front()];
                    Q.pop();
                }
                 else
                    P[I[i].id] = ++con;
               i++;
            }
    }

    printf ("%d\n", con);
    for (int i = 1; i <= n; i++){
         printf ("%d\n", P[i]);
    }

    return 0;
}
