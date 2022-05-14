/*
2015-11-13 18:22:45
https://codeforces.com/contest/598/problem/A
*/
#include <iostream>
 
using namespace std;
int cas;
typedef long long ll;
ll n, tot;
int main(){
 
    cin >> cas;
    while (cas--){
          cin >> n;
           tot = n*(n+1)/2;
           int lg = 1;
           for ( ; ll(1ll<<lg) <= n; lg++);
           tot = tot - 2ll*ll(1ll<<lg)+2;
           cout << tot<<endl;
    }
 
    return 0;
}