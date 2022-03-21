# include <cstdio>
# include <algorithm>

# define RANG 100
using namespace std;

int la, lb, s, Dp[RANG][RANG];
char A[RANG], B[RANG];

int main() {
	
	scanf ("%s", A + 1);
	scanf ("%s", B + 1);
	
	la = strlen (A + 1);
	lb = strlen (B + 1);
	
	for (int i = 0; i <= max(la, lb); i++) {
		Dp[0][i] = i;
		Dp[i][0] = i;
    }
	
	for (int i = 1; i <= lb; i++)
		for (int j = 1; j <= la; j++) {
			s = 1;
			if (B[i] == A[j])
				s = 0;
			Dp[i][j] = min (min (	  Dp[i - 1][j - 1] + s, Dp[i - 1][j] + 1), Dp[i][j - 1] + 1);
		}

    printf ("%d\n", Dp[lb][la]);
        
	return 0;
}
