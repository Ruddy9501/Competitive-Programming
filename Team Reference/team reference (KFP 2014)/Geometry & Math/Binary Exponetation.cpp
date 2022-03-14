# include <cstdio>
using namespace std;

int a, b;
const int MOD = 1000000007;

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = (a*res)%MOD;
		a = (a*a)%MOD;
		n = n >> 1;
		/**Desplaza los bits a la
		derecha y desaparece el primero*/
	}
	
	return res;
}

int main(){

	while(1){
		scanf("%d %d", &a, &b);
		printf("%d\n", binpow(a, b));
	}
	
	return 0;
}
