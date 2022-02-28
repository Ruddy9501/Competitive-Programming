/*
Censoring/plata/2015/febrero
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

#define RAN 2005
using namespace std;

int id_nod, n, id_newn, c,newn,nod,nc, nd, x, y, z;
int I[RAN], T[RAN];
long long sol, a[RAN];

struct tres{
       int nod, newn;
       long long cost;
       bool operator <(const tres &R)
       const{
             return R.cost < cost;
       }
       }A[RAN*RAN];

int bus_ide(int nod){
            if(I[nod] != nod)
               return I[nod] = bus_ide(I[nod]);
            return (I[nod]);
    }

void cam_ide(int nod, int newn){
             if(T[nod] > T[newn]){
                T[nod]+= T[newn];
                I[newn] = nod;
             }
             else{
                T[newn] += T[nod];
                I[nod] = newn;
             }
     }

int main (){

    freopen("superbull.in","r",stdin);
    freopen("superbull.out","w",stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
         scanf ("%lld", &a[i]);
         for (int j = 1; j < i; j++){
              A[++c] = (tres){i, j, (a[i]^a[j])};
        }
    }

    for(int i = 1; i <= n; i++){
        I[i] = i;
        T[i] = 1;
    }

    sort(A + 1, A + c + 1);

    for(int i = 1; i <= c; i++){
        id_nod = bus_ide(I[A[i].nod]);
        id_newn = bus_ide(I[A[i].newn]);
        if(id_nod != id_newn){
           sol += A[i].cost;
           cam_ide(id_nod, id_newn);
        }
    }

    printf("%lld\n",sol);

    return 0;
    }
