# include <cstdio>
using namespace std;

int N, i, j, k;
double M[305][305], sp;

int main(){

	scanf("%d", &N);
	for(i = 1; i <= N; i++)
		for(j = 1; j <= N+1; j++)
			scanf("%lf", &M[i][j]);

	printf("---------------------\n");

	for(i = 1; i <= N; i++)
		for(j = i+1; j <= N; j++)
			for(k = N+1; k >= i; k--)
				M[j][k] = M[j][i]*M[i][k] - M[j][k]*M[i][i];


	for(i = N; i > 0; i--){
		sp = M[i][N+1];
		for(j = i+1; j <= N+1; j++)
			sp -= M[i][j]*M[j][j];
		M[i][i] = sp/M[i][i];
	}

	for(i = 1; i <= N; i++)
		printf("%.0lf ", M[i][i]);


	return 0;
}
