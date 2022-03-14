# include <map>
# include <cstdio>
# include <algorithm>
using namespace std;

typedef long long ll;
int P[1000055], f[50], Div[50], D, x, F;

///Criba para descomponer en
///factores primos
void Criba(){
	int N = 1000007;
	for(int i = 4; i < N; i+=2)
		P[i] = 2;
	Prim[cont_Prim++] = 2;
	for(int i = 3; i*i < N; i += 2)
		if(!P[i]){
			Prim[cont_Prim++] = i;
			for(int j = i*i; j < N; j += 2*i)
				P[j] = i;
		}
}

///Factorizacion
int Fact(int n){
	int F = 0;
	while(P[n]){
		f[F++] = P[n];
		n /= P[n];
	}
	f[F++] = n;
	sort(f, f+F);
	return F;
}
///Todos los divisores de un numero
void div(int v, int ini, int fin){
	if(ini == fin){
		Div[D++] = v;
		printf("%d\n", v);
	}
	else {

		int m;
		for(m = ini+1; m < fin && f[m] == f[ini]; m++);
		for(int i = ini; i <= m; i++){
			div(v, m, fin);
			v *= f[ini];
		}
	}
}

///Cantidad de divisores de un numero
int Euler(int n, int F){
	int c = f[0];
	int v = 0;
	for(int i = 1; i <= F; i++)
		if(f[i] != f[i-1]){
		   v += (c - c/f[i-1]);
		   c = f[i];
		}
		else
		   c *= f[i];
	return v;
}

///Inverso Modular
ll MD(ll A,ll B,ll C){//return (A/B)%C
	if(A%B == 0)
		return A/B;
	return (A+(C*MD(B-(A%B),C%B,B)))/B;
}

ll Divisor_Sumation(){
 ///Productoria
	(Prim[i]^(E[i]+1)-1)/(Prim[i]-1)
	sol = 1ll;
	for (int i = 1; i <= c && P[i] <= n; i++)
		sol = (sol*MD((MOD+pow(Prim[i],E[i]+1ll)-1)%MOD,(Prim[i]-1ll),MOD))%MOD;
	}
	ll Phi(ll n){
	if(n == 1)
	   return 2;
	ll res = 1;
	for(int i = 0; i < cp && primes[i] <= n; i++){
			ll k = 1;
			ll c = 0;
		while(!(n%primes[i])){
			  n/=primes[i];
			  k*=primes[i];
			  c = (primes[i]-1);
		}
		k/=primes[i];
		if(c)
		res*=(k*c);
	}
	if(n>1)
	   res*=(n-1);
	return res;
}

int main(){

	scanf("%d",&x);
	Criba();
	F = Fact(x);
	div(1, 0, F);

	printf("Euler %d\n", Euler(x, F));
	
	return 0;
}
