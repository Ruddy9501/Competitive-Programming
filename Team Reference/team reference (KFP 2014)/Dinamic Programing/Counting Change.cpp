/**
 Sirve para ver de cuantas formas
 con una cantidad de de valores
 se puede obtener un numero
 O(M*N+M*log2(M)
 */
 
# include <cstdio>
# include <algorithm>
using namespace std;

int M, N, i, j, c[20], S[5005];

int main(){

	scanf("%d %d", &M, &N);

	for(i = 1; i <= M; i++)
		scanf("%d", &c[i]);

	sort(c+1, c+M+1);

	S[0] = 1;
	for(i = 1; i <= M; i++)
		for(j = c[i]; j <= N; j++)
			S[j] +=S[j-c[i]];

	printf("%d", S[N]);
	return 0;
}
