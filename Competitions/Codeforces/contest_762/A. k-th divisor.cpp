/*
2017-01-25 18:10:15
https://codeforces.com/contest/762/problem/A
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, k;
vector <ll> A;


int main() {

    scanf("%lld %lld", &a, &k);

    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            A.push_back(i);
            if (i * i != a) A.push_back(a / i);
        }
    }
    sort(A.begin(), A.end());
    if (A.size() >= k)
        printf("%lld\n", A[--k]);
    else printf("-1\n");

    return 0;
}