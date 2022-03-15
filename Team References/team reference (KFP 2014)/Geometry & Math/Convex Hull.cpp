# include <cstdio>
# include <algorithm>
using namespace std;

typedef long long ll;
const long long RAN = 1000;

struct par{
       ll x, y;
       par (ll a = 0, ll b = 0){
            x = a;
            y = b;
       }
       bool operator <(const par &R)
       const{
            if (R.x != x)
                return R.x > x;
             else
                return R.y > y;
       }
};

int n, can, con;
int P[RAN];
par A[RAN];

ll sol(int a, int b, int c){
        return (A[b].x - A[a].x) * (A[c].y - A[a].y)-
               (A[b].y - A[a].y) * (A[c].x - A[a].x);
}


main (){

      scanf ("%d", &n);

      for (int i = 1; i <= n; i++)
           scanf ("%lld %lld", &A[i].x, &A[i].y);

      sort (A + 1, A + n + 1);

      can++;
      for (int i = 1; i <= n; i++){
           while (can < con && sol (P[con-1], P[con], i) < 0)
                  con--;
           con++;
           P[con] = i;
      }

      can = con;
      for (int i = n - 1; i >= 1; i--){
           while (can < con && sol (P[con-1], P[con], i) < 0)
                  con--;
           con++;
           P[con] = i;
      }


      printf ("%d\n", --con);
      for (int i = 1; i <= con; i++)printf ("%lld %lld\n", A[P[i]].x, A[P[i]].y);
}
