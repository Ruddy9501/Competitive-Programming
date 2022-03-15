# include <cstdio>
# include <algorithm>

# define RANG 100
using namespace std;

int c, la, lb, Dp[RANG][RANG];
char A[RANG], B[RANG];

int main() {
	
    scanf ("%s\n", A + 1);
	scanf ("%s", B + 1);
	la = strlen (A + 1);
	lb = strlen (B + 1);
	
	for (int i = 1; i <= lb; i++)
		for (int j = 1; j <= la; j++)
			if (B[i] == A[j])
				Dp[i][j] = Dp[i - 1][j - 1] + 1;
			else
				Dp[i][j] = max (Dp[i - 1][j], Dp[i][j - 1]);
    
	printf ("%d\n", Dp[lb][la]);

	return 0;
}
