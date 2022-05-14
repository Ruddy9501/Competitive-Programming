/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008-09/Noviembre/oro
Animando las Vacas/cheer
Cruskal
*/
#include <cstdio>
#include <algorithm>

#define RAN 10005
using namespace std;

int nc, nd, id_nod, id_newn, s = 1 << 30, A[RAN], Id[RAN], Ran[RAN];

struct tri {
       int nod, newn, cos;
       bool operator < (const tri &R)
       const{
             return R.cos > cos;
       }
}V[RAN*10];

int bus_id (int nod){
    while (nod != Id[nod])
           nod = Id[nod];
    return nod;
}

void are_id(int nod, int newn){
     if (Ran[nod] > Ran[newn]){
         Ran[nod] += Ran[newn];
         Id[newn] = nod;
     }
     else{
         Ran[newn] += Ran[nod];
         Id[nod] = newn;
     }
}

int main(){

    freopen ("cheer.in", "r", stdin);
    freopen ("cheer.out", "w", stdout);

    scanf ("%d %d", &nd, &nc);
    for (int i = 1; i <= nd; i++){
         scanf ("%d", &A[i]);
          s = min (s, A[i]);
    }

    for (int i = 1; i <= nc; i++){
         scanf ("%d %d %d", &V[i].nod, &V[i].newn, &V[i].cos);
         V[i].cos = 2*V[i].cos + A[V[i].nod] + A[V[i].newn];
    }

    sort (V + 1, V + nc + 1);

    for (int i = 1; i <= nd; i++)
         Id[i] = i, Ran[i] = 1;

    for (int i = 1; i  <= nc; i++){
         id_nod = bus_id (V[i].nod);
         id_newn = bus_id (V[i].newn);
         if (id_newn != id_nod){
             s += V[i].cos;
             are_id(id_nod, id_newn);
         }
    }

    printf ("%d", s);

    return 0;
}
