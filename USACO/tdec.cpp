/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2010-11/March/Problems/Gold
Decoración de Arbol/tdec
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 100010
using namespace std;

struct par{
       int cos, nod, lev;
       par (int c = 0, int a = 0, int b = 0){
            lev = c;
            cos = a;
            nod = b;
       }
       bool operator <(const par &R)
       const{
             if (R.lev != lev)
                 return R.lev > lev;
             return R.cos < cos;
       }
};

queue <int>Q;
vector <int>V[RAN];
priority_queue<par>Q1;


int nd, nod, newn, P[RAN], M[RAN], c[RAN], Niv[RAN], la;
bool M1[RAN];
long long sol, T[RAN], C[RAN];

int main(){

    freopen ("tdec.in", "r", stdin);
    freopen ("tdec.out", "w", stdout);

    scanf ("%d", &nd);
    for (int i = 1; i <= nd; i++){
         scanf ("%d %d %d", &P[i], &M[i], &C[i]);
         c[abs(P[i])]++;
         V[P[i]].push_back(i);
    }

    Q.push(1);
    while (!Q.empty()){
           nod = Q.front();
           Q.pop();
           la = V[nod].size();
           for (int i = 0; i < la; i++){
                newn = V[nod][i];
                Niv[newn] = Niv[nod] + 1;
                Q.push(newn);
           }
    }

    for (int i = 1; i <= nd; i++)
         if (!c[i])
             Q1.push(par(Niv[i], C[i], i));

    while (!Q1.empty()){
           nod = Q1.top().nod;
           Q1.pop();
           newn = P[nod];
           if (!M1[nod]){
               M1[nod] = 1;
               if (T[nod] < M[nod]){
                   sol += ((M[nod]-T[nod])*C[nod]);
                   T[nod] = M[nod];
               }
               T[newn] += T[nod];
               C[newn] = min (C[nod], C[newn]);
               Q1.push(par(Niv[newn], C[newn], newn));
           }
    }

    printf ("%lld\n", sol);

    return 0;
}
