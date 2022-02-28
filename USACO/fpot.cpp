#include <cstdio>
#include <set>
#include <algorithm>
#define RAN 100005
#define oo 1 << 29

using namespace std;

int sol, ini, n, t, i, j, men, may;
multiset <int>M;
struct dos{
       int x, y;
       bool operator <(const dos &R)
       const{
            if (R.x != x)
                return R.x > x;
             else
                return R.y > y;
       }
}A[RAN];

int main(){

    freopen("fpot.in","r",stdin);
    freopen("fpot.out","w",stdout);

    scanf ("%d %d\n", &n, &t);

    for (int i = 1; i <= n; i++)
         scanf ("%d %d\n", &A[i].x, &A[i].y);

    sort (A + 1, A + n + 1);

    ini = 1;
    sol = oo;

    M.insert(A[1].y);
    int a = 0;
    int i = 1;
    j = 1;
    while (a == 0){     
           if (*(M.rbegin()) - *(M.begin()) >= t){
               if (sol > A[j].x - A[i].x)
                   sol = A[j].x - A[i].x;
               M.erase(M.find(A[i++].y));
           }
            else{
               if (j == n)
                   break;
               M.insert(A[++j].y);
            }
    }

    if (sol == oo)
        printf("-1\n");
     else
        printf ("%d\n",sol);

    return 0;
}
