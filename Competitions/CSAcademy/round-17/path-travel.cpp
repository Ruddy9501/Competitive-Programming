#include <bits/stdc++.h>

using namespace std;

long long n, r, b, sol, A[100005], B[100005];

int main() {

    scanf ("%lld %lld %lld", &n, &r ,&b);
    for (int i = 1; i <= r; i++)
         scanf ("%lld", &A[i]);

    for (int i = 1; i <= b; i++){
         scanf ("%lld", &B[i]);
    }

    sort (A+1,A+r+1);
    sort (B+1,B+b+1);

    B[++b] = 1ll<<30;
    B[0] = B[b]*-1ll;
    for (int i = 1; i <= r; i++){
         int p = upper_bound (B, B+b+1, A[i]) - B;
         sol += min(abs(A[i]-B[p]), abs(A[i]-B[p-1]));
    }
    printf ("%lld\n", sol);
    return 0;
}
