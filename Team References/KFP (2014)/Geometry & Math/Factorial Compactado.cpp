# include <iostream>
# include <cstdio>
# include <algorithm>
# define RANG 1000000
# define MOD 10
using namespace std;

int n, C, tmp, S;
int i, j, P[1000005], M[1000005], E[1000005];
string s;

int main() {

	//Criba, para descomponer en factores primos
	for(i = 4; i <= RANG; i += 2)P[i] = 2;
	for(i = 3; i*i <= RANG; i +=2)
		if(!P[i])
			for(j = i*i; j <= RANG; j += 2*i)
				P[j] = i;


	/**Variaciones sin repeticiones
	25'000'000, hasta mas**/

	scanf("%d %d", &n, &C);
	for(i = 1; i <= C; i++)
		scanf("%d",&M[i]);

	//Compactar factoriales
	// i! ^ E[i]
	E[n]++;
	for(i = 1; i <= C; i++){
		if(M[i] > 1)E[M[i]]--;
		M[i] = 0;
	}

	//Descompone el factorial en la productoria de sus terminos
	for(i = n-1; i >= 2; i--)
		E[i] += E[i+1];
	//Descomponer el factoria	
	//en potencias de factores primos
	for(i = n; i >= 2; i--)
		if(P[i]){
			   E[i/P[i]] += E[i];
			E[P[i]] +=E[i];
			E[i] = 0;
		}

	//Especificidad para eliminar los
	//ultimos digitos iguales a 0
	tmp = min(E[2], E[5]);
	E[2] -= tmp; E[5] -= tmp;

	//Calcular la Variacion expresada
	//en la productoria de factores primos
	S = 1;
	for(i = 2; i <= n; i++){
	    S = (S * modexp(i, E[i])) % 10;
	    E[i] = 0;
	}

	printf("%d\n", S);

	return 0;
}
