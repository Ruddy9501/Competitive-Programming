/*
Ruddy Guierrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008/mar08/bronze
Ah Esos Rodillos/rollers
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 1100
using namespace std;

int p, n, D[RAN], X[RAN], Y[RAN];
bool M[RAN];
queue <int>Q;

long long dis (int a, int b){
     return (X[a]-X[b])*(X[a]-X[b])+(Y[a]-Y[b])*(Y[a]-Y[b]);
}

int main(){

    freopen ("rollers.in", "r", stdin);
    freopen ("rollers.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d %d", &X[i], &Y[i], &D[i]);
         if (X[i] == Y[i]  && X[i] == 0)
             p = i, M[i] = 1;
         X[i] += 5000;
         Y[i] += 5000;
    }

    Q.push(p);
    while (!Q.empty()){
           p = Q.front();
           Q.pop();
           for (int i = 1; i <= n; i++){
                if (M[i] == 1)continue;
                if (dis(i, p) == (D[i]+D[p])*(D[i]+D[p]))
                    Q.push(i), M[i] = 1;
           }
    }

    printf ("%d %d\n", X[p]-5000, Y[p]-5000);

    return 0;
}
