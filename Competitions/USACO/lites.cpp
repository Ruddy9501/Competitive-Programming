/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO/Problems/2008-09/Noviembre/oro
Prendiendo Luces/lites
Segment Tree
*/
#include <cstdio>
#include <algorithm>

#define RAN 200010
using namespace std;

int n, m, a, b, r;

struct sc{
       int A[RAN*3], M[RAN*3];

       void leisi(int ini, int fin, int pos){
            M[pos] = 0;

            if (ini == fin)
                return ;

            M[pos*2] = (M[pos*2]+1) % 2;
            M[pos*2+1] = (M[pos*2+1]+1) % 2;

            int piv = (ini+fin) / 2;
            A[pos*2] = piv-ini-A[pos*2]+1;
            A[pos*2+1] = fin-piv-A[pos*2+1];

       }

       void cons(int ini, int fin, int pos){

           if (M[pos])
               leisi(ini, fin, pos);

           if (b < ini || fin < a)
               return ;

           if (a <= ini && fin <= b){
               M[pos] = 1;
               A[pos] = fin-ini-A[pos]+1;
               return ;
           }

           int piv = (fin+ini) / 2;
           cons(ini, piv, pos*2);
           cons(piv+1, fin, pos*2+1);
           A[pos]= A[pos*2] + A[pos*2+1];
       }

       int preg(int ini, int fin, int pos){

           if (M[pos])
               leisi (ini, fin, pos);

           if (b < ini || fin < a)
               return 0;

           if (a <= ini && fin <= b)
               return A[pos];

           int piv = (ini+fin) / 2;
           return (preg(ini, piv, pos*2) + preg(piv+1, fin, pos*2+1));
       }

} S;

int main(){

   // freopen ("lites.in", "r", stdin);
   // freopen ("lites.out", "w", stdout);

    scanf ("%d %d", &n, &m);

    //S.cons(1, n, 1);
    for (int i = 1; i <= m; i++){
         scanf ("%d %d %d", &r, &a, &b);
         if ( r )
             printf ("%d\n", S.preg(1, n, 1));
          else
             S.cons(1, n, 1);
    }

    return 0;
}
