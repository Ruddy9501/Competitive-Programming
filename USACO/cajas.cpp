/*
Ruddy Guerrero Alvarez
Caibarien--Villa Clara
Cajas\Nacional 2012
*/
#include <algorithm>
#include <cstdio>

#define RAN 100005 

using namespace std;

long long promedio, total, mediana, sol, n;
int A[RAN];

int main (){

    freopen ("cajas.in","r",stdin);
    freopen ("cajas.out","w",stdout);

    scanf ("%I64d\n", &n);

    for (int i = 1; i <= n; i++){
	     scanf ("%d", &A[i]); 
		 total += A[i];
	} 
     
	promedio = total / n;

    for (int i = 1; i <= n; i++)
	     A[i] = A[i] - promedio + A[i-1];
	
	sort (A + 1, A + n + 1);
    mediana = A[(n/2) + 1];
  	
   	for (int i = 1; i <= n; i++)
	    sol += abs(A[i] - mediana); 
	
	printf ("%I64d\n",sol);

    return 0;
}
