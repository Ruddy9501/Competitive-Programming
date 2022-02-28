/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
PRUEBA EXPLORATORIA #2 PSN 2009
Segments Tree
*/
#include <cstdio>
#include <algorithm>

#define RAN 100000
using namespace std;

int n, a, b, s;

struct st{
       int A[RAN*3];

       void cons(int ini, int fin, int pos){

           if ( b < ini || fin < a )
               return ;

           if (a <= ini && fin <= b){
               A[pos]++;
			   return ;
		   }

           int piv = (ini+fin) / 2;
           cons(ini, piv, pos*2);
		   cons(piv+1, fin, pos*2+1);
	   }

       int preg(int ini, int fin, int pos, int P){

                if (ini == fin && ini == P){
                    int r = A[pos];
					A[pos] = 0;
					return r;
				}

				A[pos*2] += A[pos];
				A[pos*2+1] += A[pos];
				A[pos] = 0;

                int piv = (ini+fin) / 2;
                if (piv < P)
                    preg (piv+1, fin, pos*2+1, P);
                 else
                    preg (ini, piv, pos*2, P);
	   }
}S;
int main(){

    freopen ("cvjetici.in", "r", stdin);
    freopen ("cvjetici.out", "w", stdout);

    scanf ("%d", &n);
    for (int i= 1; i <= n; i++){
         scanf ("%d %d", &a, &b);
         printf ("%d\n", S.preg(1, RAN, 1, a)+ S.preg(1, RAN, 1, b));
         a++, b--;
         S.cons (1 , RAN, 1);
    }

    return 0;
}
