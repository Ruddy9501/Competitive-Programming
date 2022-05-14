#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n, m, a;
multiset <ll> A;
multiset <ll> :: iterator it;

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
         cin >> a;
         A.insert(a);
    }

    for (int i = 1; i <= m; i++){
         cin >> a;
       
         it = A.upper_bound(a);
         if (it == A.end()){
             cout << "-1" << endl;
             return 0;
         }
         A.erase(it);
    }

    ll sol = 0;
    for ( it = A.begin(); it != A.end(); it++)
         sol += *it;

    cout << sol << endl;

    return 0;
}
