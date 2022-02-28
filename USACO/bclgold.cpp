/*
Ruddy Guerrero Alvarez
Caibarien--Villa Clara
Mejor Fila Vacuna\bclgold\Oro
USACO\2007\diciembre\Greedy
*/
#include <cstdio>
#include <cstring>
#define RAN 30005

using namespace std;

int fin, ini, con, c, a, n, t;
char A[RAN], S[RAN];

void imprimir(char A){
     if (con == 80){
         printf("\n"); 
         con = 0;
     }
     printf ("%c",A);
     con++;        
} 

int main(){

    freopen("bclgold.in","r",stdin);
    freopen("bclgold.out","w",stdout);

    scanf ("%d\n",  &n);

    t = strlen(A);

    for (int i = 0; i < n; i++)
         scanf ("%c\n", &A[i]);

    ini = 0;
    fin = n-1;
    while (ini <= fin){
           if (A[ini] < A[fin]){
               imprimir (A[ini]);
               ini++;
           }
           else
            if (A[ini] > A[fin]){
                imprimir (A[fin]);
                fin--;
            }
            else{
                 int i = ini+1;
                 int f = fin-1;
                while (A[i] == A[f] && f - i > 1){
                       i++; f--;
                }
                
                if (A[i] < A[f]){
                    imprimir (A[ini]);
                    ini++;
                }
                 else{   
                    imprimir (A[fin]);
                    fin--; 
                 }
            }
    }

    return 0;
}
