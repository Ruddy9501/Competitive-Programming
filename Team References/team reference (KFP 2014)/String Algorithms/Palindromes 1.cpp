//O(n^2)
# include <cstdio>
# include <cstring>
using namespace std;

int i, j, ls;
bool m[5005][5005];
char s[5005];

int main(){

	scanf("%s", s+1);
	ls = strlen(s+1);
	for(i = 1; i <= ls; i++)
		m[1][i] = true;

	for(i = 2; i <= ls; i++){
		for(j = i; j <= ls; j++)
			if(s[j] == s[j-i+1] && m[i-(i > 2? 2:1)][j-1])
				m[i][j] = true;
	}

	return 0;
}
