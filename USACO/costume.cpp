/*
Ruddy Guerrero Alvarez
Caibarien--Villa Clara
Baile de Disfraces\costume\
USACO\enero\2007\bronce
ABI
*/
#include <cstdio>
#include <algorithm>
#define RAN 2000005

using namespace std;

int n, m, sol, a, x;
int C[RAN];

void sumar(int ini, int fin){
     for (int i = ini; i <= fin; i += (i & -i)){
	      C[i] += 1;  
	 } 
}

int bus_val(int ini){
    int total = 0;
    for (int i = ini; i >= 1; i -= (i & -i))
         total += C[i];
    return total; 		 
}

int main (){
    
	freopen ("costume.in","r",stdin);
    freopen ("costume.out","w",stdout);

    scanf ("%d %d\n", &n, &m);

    for (int i =1; i <= n; i++){
	     scanf ("%d\n", &x);
	     a = bus_val(m-x);
		 if (a <= m)
		     sol += a;
         sumar(x, m); 		 
	} 	
    
    printf ("%d",sol);
	
    return 0; 
}
