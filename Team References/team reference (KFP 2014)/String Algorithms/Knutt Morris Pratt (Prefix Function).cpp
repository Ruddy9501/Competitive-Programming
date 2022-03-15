/**
Determina las ocurrencias de un
patron dentro de un texto
O(N+M)
*/
# include <cstring>
# include <cstdio>
using namespace std;

int i, k, lp, lt;
int F[5005];
char Text[5005], Pattern[5005];

int main(){

	scanf("%s\n%s", Text+1, Pattern+1);
	lp = strlen(Pattern + 1);
	lt = strlen(Text + 1);

	for(i = 2; i <= lp; i++){
		while(k > 0 && Pattern[k + 1] != Pattern[i])
			k = F[k];

		if(Pattern[k + 1] == Pattern[i])
			k++;

		F[i] = k;
	}

	k = 0;
	for(i = 1; i <= lt; i++){
		while(k > 0 && Pattern[k + 1] != Text[i])
			k = F[k];

		if(Pattern[k + 1] == Text[i])k++;

		if(k == lp){
			printf("%d ", i-lp+1);
			k = F[k];
		}
	}

	return 0;
}
