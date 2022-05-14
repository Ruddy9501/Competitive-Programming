/*
Ruddy Guerrero Alvarez
USACO/2008-2009/octubre/bronce
Pozos de Agua/water
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 305
using namespace std;
typedef pair<int, int>par;

int n, a, a1, b, b1, sol, can, A[RAN][RAN];
bool M[RAN];
priority_queue <par, vector <par>, greater<par> >Q, Q1;

int main(){

    freopen ("water.in", "r", stdin);
    freopen ("water.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
         Q.push(par(a, i));
    }

    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= n; j++)
              scanf ("%d", &A[i][j]);

    while (can != n){

           while (!Q.empty() && M[Q.top().second] == true)
                  Q.pop();
           while (!Q1.empty() && M[Q1.top().second] == true)
                  Q1.pop();

           a = Q.top().first;
           b = Q.top().second;
           a1 = b1 = 99999999;
           if (!Q1.empty()){
               a1 = Q1.top().first;
               b1 = Q1.top().second;
           }
           if (a <= a1){
               Q.pop();
               sol += a;
               can++;
               M[b] = true;
               for (int i = 1; i <= n; i++)
                    if (M[i] == false)
                        Q1.push(par(A[b][i], i));
           }
           else{
               Q1.pop();
               sol += a1;
               can++;
               M[b1] = true;
               for (int i = 1; i <= n; i++)
                     if (M[i] == false)
                         Q1.push(par(A[b1][i], i));
           }
    }

    printf ("%d\n", sol);

    return 0;
}
