/*
Ruddy Guerrero Alvarez
Villa Clara - Caibarien
El Gran Baile/bigdance/USACO 2009-2010/diciembre/bronce
Muy facil
*/
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef pair <int,int>par;

int n, f, i;
long long sol;
queue <par>Q;

int main(){

    freopen ("bigdance.in", "r", stdin);
    freopen ("bigdance.out", "w", stdout);

    scanf ("%d", &n);

    Q.push (par(0,n));
    while (!Q.empty()){
           i = Q.front().first;
           f = Q.front().second;
           Q.pop();
           if (f - i > 2){
               Q.push(par(i,i+(f-i+1)/2));
               Q.push(par(i+(f-i+1)/2,f));
           }
            else
               if (f - i == 2)
                   sol += f * (i+1);
    }

    printf ("%lld", sol);

    return 0;
}
