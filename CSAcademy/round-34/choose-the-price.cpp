#include <bits/stdc++.h>

using namespace std;

long long A[1005], sol;

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%lld", &A[i]); 
    
    sort (A+1,A+n+1);
    for (int i = 1; i <= n; i++)
         sol = max(sol, A[i]*(n-i+1)); 

    printf ("%lld\n", sol);
    
    return 0;
}