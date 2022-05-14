#include <bits/stdc++.h>

using namespace std;

long long n, m, sol;
const long long MOD = 1e9 + 7;

int main(){
    
    scanf ("%lld %lld", &n, &m);

    for (int i = 1; i <= min(n, m); i++){
         sol = (sol + ((n-i+1) * (m-i+1)) % MOD) % MOD;
         sol += (((n-i+1) * (m-i+1)) % MOD * (i-1)) % MOD;
         sol %= MOD; 
    }

    printf ("%lld\n", sol);

	return 0;
}