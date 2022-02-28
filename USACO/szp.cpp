/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
1A EXPLORA #4 PSN 2013
Espías/szp
*/
# include <queue>
# include <cstdio>
# include <algorithm>

#define RAN 1000010
using namespace std;

int n, nod, B[RAN], A[RAN], r;
bool M[RAN];

queue <int>Q;


int main(){

    freopen ("szp.in", "r", stdin);
    freopen ("szp.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &B[i]);
         A[B[i]]++;
    }

    for (int i = 1; i <= n; i++){
         if (A[i] == 0)
             Q.push(i);
    }

    while (!Q.empty()){
           nod = Q.front();
           Q.pop();
           if (!M[B[nod]]){
               M[nod] = M[B[nod]] = 1;
               r++;
               if (!M[B[B[nod]]] && --A[B[B[nod]]] == 0)
                   Q.push(B[B[nod]]);
           }
    }

    for (int i = 1; i <= n; i++){
         if (!M[i]){
             nod = i;
             while (!M[nod] && !M[B[nod]]){
                    M[nod] = M[B[nod]] = 1;
                    nod = B[B[nod]];
                    r++;
             }
         }
    }

    printf ("%d\n", r);

    return 0;
}
