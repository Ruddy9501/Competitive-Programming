/*
2016-04-05 16:44:15
https://codeforces.com/contest/387/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, m, sol, A[5005], B[5005];
map <int, int> M;
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
         cin >> A[i];
 
    for (int i = 1; i <= m; i++)
        cin >> B[i];
 
    int i, pos = 1;
    for (i = 1; i <= m && pos <= n; i++){
         if (A[pos] <= B[i] && pos<=n )pos++;
    }
    pos--;
    cout << n-pos << "\n";
 
    return 0;
}