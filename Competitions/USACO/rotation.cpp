/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/octubre/bronce
Rotación de Ruedas/rotation
brute force
*/
#include <cstdio>
#include <vector>

#define RAN 1005
using namespace std;
typedef pair<int, int>par;

int n, a, b, c, pos, dir;
vector <par>V[RAN];

int main(){

    freopen ("rotation.in", "r", stdin);
    freopen ("rotation.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i < n; i++){
         scanf ("%d %d %d", &a, &b, &c);
         V[a].push_back(par(b, c));
    }

    pos = 1;
    while (n != pos){
           if (V[pos][0].second == 1)
               if (dir == 0)
                   dir = 1;
                else
                   dir = 0;
           pos = V[pos][0].first;
    }

    printf ("%d\n", dir);

    return 0;
}
