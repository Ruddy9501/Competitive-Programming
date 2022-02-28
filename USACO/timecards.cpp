/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/open/bronce
Tarjetas/timecards
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#define RAN 150
using namespace std;
typedef pair<int,int> par;

int n, m, id, a, b;
char cad[150];
int C[RAN], S[RAN];

int main(){

    freopen ("timecards.in", "r", stdin);
    freopen ("timecards.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= m; i++){
         scanf ("%d %s %d %d\n", &id, cad, &a, &b);
         if (cad[2] == 'A'){
             C[id] = a*60+b;
         }
         else{
             S[id] += (a*60+b) - C[id];
         }
    }

    for (int i = 1; i <= n; i++){
         printf ("%d %d\n",S[i]/60, S[i]%60);
    }

    return 0;
}
