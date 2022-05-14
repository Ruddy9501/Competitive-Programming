/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
PSN EXPLORA#1
Tetris/tetris
BRUTE FORCE
*/
#include <cstdio>

#define RAN 105
using namespace std;

int i, n, m, sol, A[RAN];

void p1(){
     if (A[i-3] == A[i-2] && A[i-1] == A[i] && A[i] == A[i-3])
         sol++;
};

void p2(){
     if (A[i] == A[i-1])
         sol++;
}

void p3(){
     if (i > 2 && A[i-2] == A[i-1] && A[i-1]+1 == A[i])
         sol++;
     if (i > 1 && A[i-1]-1 == A[i])
         sol++;
}

void p4(){
     if (i > 2 && A[i] == A[i-1] && A[i-1]+1 == A[i-2])
         sol++;
     if (i > 1 && A[i-1]+1 == A[i])
         sol++;
}

void p5(){
     if (i > 1 && A[i-1]-1 == A[i])
         sol++;
     if (i > 1 && A[i-1]+1 == A[i])
         sol++;
     if (i > 2 && A[i-2] == A[i-1] && A[i] == A[i-1])
         sol++;
     if (i > 2 && A[i-2] == A[i] && A[i]-1 == A[i-1])
         sol++;
}

void p6(){
     if (i > 2 && A[i-2] == A[i-1] && A[i-1] == A[i])
         sol ++;
     if (i > 1 && A[i-1]-2 == A[i])
         sol++;
     if (i > 1 && A[i-1] == A[i])
         sol++;
     if (i > 2 && A[i] == A[i-1] && A[i-1]-1 == A[i-2])
         sol++;
}

void p7(){
     if (i > 2 && A[i-2] == A[i-1] && A[i-1] == A[i])
         sol++;
     if (i > 1 && A[i-1] == A[i])
         sol++;
     if (i > 2 && A[i-1] == A[i-2] && A[i-1]-1 == A[i])
         sol++;
     if (i > 1 && A[i-1]+2 == A[i])
         sol++;
}

int main(){

    freopen ("tetris.in", "r", stdin);
    freopen ("tetris.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
         scanf ("%d", &A[i]);

    if (m == 1)
        sol = n;

    for (i = 1;  i <= n; i++){

         if (m == 1 && i > 3){
             p1 ();
         }

         if (m == 2 && i > 1){
             p2 ();
         }

         if (m == 3)
             p3 ();

         if (m == 4)
             p4 ();

         if (m == 5)
             p5 ();

         if (m == 6)
             p6 ();

         if (m == 7)
             p7 ();
    }

    printf ("%d\n", sol);

    return 0;
}
