/*
Ruddy Guerrero Alvarez
12mo
Villa Clara
IPVCE:Ernesto Guevara
DIA 7
USACO/2006/marzo/oro
Moo/mooo
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 50005
using namespace std;
typedef pair<int, int>par;

struct dos{
       long long alt;
       int  val;
       dos(long long a = 0, int b = 0){
           alt = a;
           val = b;
       }
       bool operator <(const dos &R)
       const {
              return R.alt < alt;
       }
};

long long n, m, sol, T[RAN];
par A[RAN];
priority_queue <dos>Q;

int main(){

    freopen ("mooo.in", "r", stdin);
    freopen ("mooo.out", "w", stdout);

    scanf ("%lld\n", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%lld %lld\n", &A[i].first, &A[i].second);

    for (int i = 1; i <= n; i++){
         while (!Q.empty() && Q.top().alt < A[i].first){
                T[i] += Q.top().val;
                Q.pop();
         }
         Q.push(dos(A[i].first, A[i].second));
    }

    while (!Q.empty())
           Q.pop();

    for (int i = n; i >= 1; i--){
         while (!Q.empty() && Q.top().alt < A[i].first){
                 T[i] += Q.top().val;
                Q.pop();
         }
         Q.push(dos(A[i].first, A[i].second));
    }

    for (int i = 1; i <= n; i++)
         if (sol < T[i])
             sol = T[i];

    printf ("%lld\n", sol);

    return 0;
}
