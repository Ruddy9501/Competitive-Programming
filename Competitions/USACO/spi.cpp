/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Mision de espias/spi
Cruskal
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int c, a, nod, newn, id_nod, id_newn, n, Ran[1010], Id[1010], C[1010], s;
bool M[1010][1010], M1[1010];

struct tri{
       int nod, newn, cos;
       bool operator <(const tri &R)
       const{
            return R.cos > cos;
       }
}A[1000010];

int bus_id(int nod){
    while (Id[nod] != nod){
           nod = Id[nod];
    }
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

    freopen ("spi.in", "r", stdin);
    freopen ("spi.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         for (int j = 1; j <= n; j++){
              scanf ("%d", &a);
              if (!M[i][j]){
                  M[i][j] = M[j][i] = 1;
                  A[++c].nod = i;
                  A[c].newn = j;
                  A[c].cos = a;

              }
         }
    }

    for (int i = 1; i <= n; i++){
         scanf ("%d", &C[i]);
         Id[i] = i;
         Ran[i] = 1;
         A[++c].cos = C[i];
         A[c].nod = i;
         A[c].newn = n+1;

    }

    sort (A + 1, A + c + 1);

    for (int i = 1; i <= c; i++){
         id_nod = bus_id(A[i].nod);
         id_newn = bus_id(A[i].newn);
         if (id_nod != id_newn){
             s += A[i].cos;
             are_id(id_nod, id_newn);
         }
    }

    printf ("%d\n", s);

    return 0;
}
