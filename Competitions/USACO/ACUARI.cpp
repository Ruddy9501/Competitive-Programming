/*
Ruddy Guerrero Alvarez
PSN 2012
*/
#include <cstdio>
#include <algorithm>
#define RAN 10000100

using namespace std;

int may, men, sol, n, t, c;
int S[RAN], R[RAN];

int main(){

    freopen ("ACUARI.in","r",stdin);
    freopen ("ACUARI.out","w",stdout);

    scanf ("%d\n", &men);
    scanf ("%d\n", &may);
    scanf ("%d\n", &n);

    for (int i = 1; i <= n; i++){
         scanf ("%d", &t);
         R[t*2] += 1;
         S[(t*10)+1] += 1;
        if (t % 10 != 0)
             R[(t / 10)+ 1] += 1;
          else     
             R[t / 10] += 1; 
         S[(t / 2) + 1] += 1;
    }


    for (int i = 0; i <= may; i++){
         c += S[i];
         c -= R[i];
		 //if (i >= men)!ponme si se empiesa desde el inicio y no desde cero!
		 if (c >= 0){
             sol++;
         }
    }
    
    printf ("%d\n",sol);
    return 0;
}
