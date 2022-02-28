#include <bits/stdc++.h>

using namespace std;

int n, m, con;
long long A[100005], sol;
vector <int>v;

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }

    for (int i = 30; i >= 0; i--){
         con = 0;
         v.clear();
         for (int j = 1; j <= n; j++){
              if ((1ll << i) & A[j])
                 con++, v.push_back(A[j]);
         }

         if (con >= m){
             for (int j = 0; j < (int)v.size(); j++){
                  A[j+1] = v[j];
             }
             n = v.size();
             sol += 1ll<<i;
         }
    }

    cout << sol << "\n";

    return 0;
}
