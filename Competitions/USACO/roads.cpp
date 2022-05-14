/*
************************************
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
** Construyendo Caminos\roads\     **
** USACO\2007\diciembre\          ** 
** plata\Kruscal                  **
************************************
*/
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define RAN 10010
#define MAX 1000000

using namespace std;

struct tres {
       long long nod, newn;
       double cos;
       tres (long long a = 0, long long b = 0, double c = 0){
             nod = a;
             newn = b;
             cos = c;
       }
       bool operator <(const tres &R)
       const {
              return R.cos > cos;
       }

}S[MAX];

long long id_newn, id_nod, nod, newn, n, m, c;
double cos1, sol;
long long Ran[RAN], Id[RAN], A[RAN], B[RAN];

void sum_ran(long long nod, long long newn){
     if (Ran[nod] > Ran[newn]){
         Ran[nod] += Ran[newn];
         Id[newn] = nod;
     }
     else{
         Ran[newn] += Ran[nod];
         Id[nod] = newn;
     }
}

int bus_id(long long  nod){
    if (Id[nod] != nod)
        bus_id (Id[nod]);
     else
        return nod;
}

int main (){

    freopen("roads.in","r",stdin);
    freopen("roads.out","w",stdout);

    scanf ("%I64d %I64d\n", &n, &m);

    for (int i = 1; i <= n; i++)
         scanf ("%I64d %I64d\n", &A[i], &B[i]);

    for (int i = 1; i <= n-1; i++){
         for (int j = i+1; j <= n; j++){
              long long nod = (A[i] - A[j]) * (A[i] - A[j]);
              long long newn = (B[i] - B[j]) * (B[i] - B[j]);
              cos1 = sqrt(nod+newn);
              S[++c].nod =  i;
              S[c].newn = j;
              S[c].cos = cos1;
         }
    }

    for (int i = 1; i <= m; i++){
         scanf ("%I64d %I64d", &nod, &newn);
         S[++c].nod =  nod;
         S[c].newn = newn;
         S[c].cos = 0;
    }

    for (int i = 1; i <= n; i++){
         Ran[i] = 1;
         Id[i] = i;
    }

    sort(S +1, S + c + 1);

    for (int j = 1; j <= c; j++){
         id_nod = bus_id(S[j].nod);
         id_newn = bus_id(S[j].newn);
         if (id_newn != id_nod){
             sum_ran(id_nod, id_newn);
             sol += S[j].cos;
         }
    }

    printf ("%.2lf\n",sol);

    return 0;
    }

