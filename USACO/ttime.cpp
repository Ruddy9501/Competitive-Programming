/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
/USACO/Problems/2009-10/Enero/Problems/Silver
Hora del Té/ttime
*/
#include <cstdio>

#define RAN 1005
using namespace std;

int n, m, p, a, b, id_a, id_b, Id[RAN], Ran[RAN];

int bus_id(int nod){
    while (Id[nod] != nod)
           nod = Id[nod];
    return nod;
}

void unir (int nod , int newn){
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

    freopen ("ttime.in", "r", stdin);
    freopen ("ttime.out", "w", stdout);

    scanf ("%d %d %d", &n, &m, &p);

    for (int i = 1; i <= n; i++)
         Ran[i] = 1, Id[i] = i;

    for (int i = 1; i <= m; i++){
         scanf ("%d %d", &a, &b);
         id_a = bus_id(a);
         id_b = bus_id(b);
         if (id_a != id_b)
             unir (id_a, id_b);
    }

    for (int i = 1; i <= p; i++){
         scanf ("%d %d", &a, &b);
         id_a = bus_id(a);
         id_b = bus_id(b);
         if (id_a == id_b)
             printf ("Y\n");
          else
             printf ("N\n");
    }

    return 0;
}
