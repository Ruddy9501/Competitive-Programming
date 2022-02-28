/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/open/bronce
Tarjetas/timecards
greedis
*/
#include <queue>
#include <cstdio>

using namespace std;

int n, a, atr, pre, sol;
priority_queue<int, vector<int>, greater<int> >Q;

int main(){

    freopen ("fads.in", "r", stdin);
    freopen ("fads.out", "w", stdout);

    scanf ("%d %d %d", &n, &atr, &pre);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         Q.push(a);
    }

    while (!Q.empty() && Q.top() <= atr){
           sol++;
           Q.pop();
           atr += pre;
    }

    printf ("%d\n", sol);

    return 0;
}
