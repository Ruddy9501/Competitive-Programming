/*
Ruddy Guerrero Alvarez
VILLA CLARA -> CAIBARIEN
PSN 2013 PRUEBA EXPLORTORIA #2
AD-HOC
El Móvil más liviano/mobil
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 1000
using namespace std;
typedef pair<int, int>par;

long long a, b, n, r, g, m1, m2, a1,sol, nod, newn, P;
long long CT[RAN], P1[RAN], P2[RAN];
par A[RAN], S[RAN], H[RAN];
bool M[RAN];

queue <int>Q;

int gsd(int a, int b){
    while (a){
           swap(a, b);
           a %= b;
    }
    return b;
}

main (){

      freopen ("mobile.in", "r", stdin);
      freopen ("mobile.out", "w", stdout);
      CT[0] = 1;
      scanf ("%d", &n);
      for (int i = 1; i <= n; i++){
           scanf ("%d %d %d %d", &a, &a1, &r, &b);
           g = gsd (a, a1);
           P1[r] = i;
           P2[b] = i;
           A[i] = (par){a/g, a1/g};
           if (r == 0 && b == 0){
               CT[i] = (a*a1)/g/a + (a*a1)/g/a1;
               if (n > 1)Q.push(i);
           }
           M[r] = M[b] = 1;
           S[i] = (par) {(a*a1)/g/a,(a*a1)/g/a1};
           H[i] = (par) {r, b};
      }

      for (P = 1; M[P]; P++);

     while (!Q.empty()){
           nod = Q.front();
           Q.pop();
           newn = P1[nod];
           if (newn && newn != P){
               m1 = CT[nod]*A[newn].first;
               m2 = S[newn].second*A[newn].second;
               g = gsd (m1, m2);
               S[newn] = (par) {(m1 * m2)/g/A[newn].first,
                               (m1 * m2)/g/A[newn].second};
               CT[newn] = S[newn].first+S[newn].second;
               Q.push(newn);
           }
           newn = P2[nod];
           if (newn && newn != P){
               m1 = CT[nod]*A[newn].second;
               m2 = S[newn].first*A[newn].first;
               g = gsd (m1, m2);
               S[newn] = (par) {(m1 * m2)/g/A[newn].first,
                               (m1 * m2)/g/A[newn].second};
               CT[newn] = S[newn].first+S[newn].second;
               Q.push(newn);
           }
      }

      m1 = CT[H[P].first] * A[P].first;
      m2 = CT[H[P].second] * A[P].second;
      g = gsd (m1, m2);
      sol = (m1*m2/g/A[P].first)+(m1*m2/g/A[P].second);

      printf ("%d\n", sol);

}
