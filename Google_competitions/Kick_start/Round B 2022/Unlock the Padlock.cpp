#include <bits/stdc++.h>

using namespace std;

const int RAN = 405;
int cas, n, k, a[RAN];
long long dp[RAN][RAN][2];

long long solve(int ini, int fin, int b){
    
    if (dp[ini][fin][b] != -1) return dp[ini][fin][b];
    
    if (b == 0){
        long long s1 = min((k + a[ini] - a[ini + 1]) % k, (k + a[ini + 1] - a[ini]) % k);
        dp[ini][fin][b] = solve (ini + 1, fin, 0) + s1;
        long long s2 = min((k + a[ini] - a[fin]) % k, (k + a[fin] - a[ini]) % k);
        dp[ini][fin][b] = min (dp[ini][fin][b], solve (ini+1, fin, 1) + s2);
    }
    else{
        long long s1 = min((k + a[fin] - a[ini]) % k, (k + a[ini] - a[fin]) % k);
        dp[ini][fin][b] = solve (ini, fin-1, 0) + s1;
        long long s2 = min((k + a[fin] - a[fin - 1]) % k, (k + a[fin-1] - a[fin]) % k);
        dp[ini][fin][b] = min (dp[ini][fin][b], solve (ini, fin-1, 1) + s2);
    }
    
    return dp[ini][fin][b];
}


int main(){
    
    scanf ("%d", &cas);
    for (int i = 1; i <= cas; ++i){
        scanf ("%d %d", &n, &k);
        memset (dp, -1, sizeof(dp));
        
        for (int j = 1; j <= n; ++j){
             scanf ("%d", &a[j]);
             dp[j][j][0] = dp[j][j][1] = 0;
        }
        
        long long sol = min (solve (1, n, 0) + min((k - a[1]) % k, a[1]), solve (1, n, 1) + min((k - a[n]) % k, a[n]));
        
        printf ("Case #%d: %lld\n", i, sol);
    }
    
    
    return 0;
}
