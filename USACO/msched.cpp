/*
Ruddy Guerrero Alvarez
Horario de Ordeño
USACO/2013-2014/plata
*/

#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 10005
using namespace std;

int n, sol, tope, tiempo;

priority_queue <int , vector <int>, greater<int> >Q;

struct par{
       int t, c;
       bool operator < (const par R)const{
            if (R.t != t)
                return R.t > t;
             else
                return R.c < c;
       }
}A[RAN];

int main(){

    freopen ("msched.in", "r", stdin);
    freopen ("msched.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d %d", &A[i].c, &A[i].t);

    sort (A + 1, A + n + 1);

    for (int i = 1; i <= n; i++){

         if (tiempo < A[i].t ){
             Q.push(A[i].c);
             sol += A[i].c;
             tiempo++;
         }
          else{
             tope = Q.top();
             if (tope < A[i].c){
                 Q.pop();
                 Q.push(A[i].c);
                 sol += A[i].c - tope;
             }
          }
    }

    printf ("%d\n", sol);

    return 0;
}
