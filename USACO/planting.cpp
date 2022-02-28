/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2011-12\February\bronce
Sobreplantando\planting
Area de union(Sweep line)
*/
#include <set>
#include <cstdio>
#include <algorithm>

#define RAN 1005
using namespace std;
typedef pair<int, int>par;

struct cua {
       int x1, y1, x2, y2;
}A[RAN];

int n ,a, b, d, c, c1, id, con, ult;
bool M[RAN];
long long s, mul;
par B[RAN*2];
multiset <par, less<par> >Ms;
multiset <par, less<par> >::iterator it;

int main(){

    freopen ("planting.in", "r", stdin);
    freopen ("planting.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d %d %d", &a, &b, &c, &d);
         A[i] = (cua){a, b, c, d};
         B[++c1] = (par){a, i};
         B[++c1] = (par){c, i};
    }

    sort (B + 1, B + c1 + 1);

    for (int i = 1; i <= c1; i++){

         id = B[i].second;
         if (!M[id])
             Ms.insert (par(A[id].y1, 1)),
             Ms.insert (par(A[id].y2, -1));
          else
             Ms.erase (Ms.find(par(A[id].y1, 1))),
             Ms.erase (Ms.find(par(A[id].y2, -1)));

         s += (mul * abs(B[i].first - B[i-1].first));
         M[id] = 1;

         for (it = Ms.begin(), con = 0, mul = 0; it != Ms.end(); it++){

              if (con == 0)
                  ult = it -> first;

              con += it -> second;
              if (con == 0)
                  mul = mul + it -> first - ult;
         }

    }

    printf ("%lld\n", s);

    return 0;
}
