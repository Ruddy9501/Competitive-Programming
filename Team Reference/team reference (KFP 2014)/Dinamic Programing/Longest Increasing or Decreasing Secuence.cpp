# include <cstdio>
# include <algorithm>
using namespace std;

int i, j, n, s, sol[505], L[505], Id[505], a[505], up;

int main(){
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for(i = 1; i <= n; i++){
		if(a[i] > sol[s]){
			sol[++s] = a[i];
			Id[s] = i;
			L[i] = Id[s-1];
		}
		else{
			up = upper_bound(sol+1, sol+s+1, a[i])-sol;
			sol[up] = a[i];
			Id[up] = i;
			L[i] = Id[up-1];
		}
	}

	printf("%d", s);
	return 0;
}
