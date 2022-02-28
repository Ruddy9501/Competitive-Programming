/*
Ruddy Guerrero Alvarez
12
Villa Clara -> Caibarien
USACO/ORO/noviembre/2006
Reparación de Cerca/plank
dinamica
*/
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

struct uno{
       int val;
       uno (int a = 0){
            val = a;
       }
       bool operator < (const uno &R)
       const {
              return R.val < val;
       }
};

long long n ,a, b, sol;
priority_queue <uno>Q;

int main(){

    freopen ("plank.in", "r", stdin);
    freopen ("plank.out", "w", stdout);

    scanf ("%lld", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%lld", &a);
         Q.push(uno(a));
    }


    while (Q.size() != 1){
           a = Q.top().val;
           Q.pop();
           b = Q.top().val;
           Q.pop();
           Q.push(uno(a+b));
           sol += (a+b);
    }

    printf ("%lld\n", sol);

    return 0;
}
