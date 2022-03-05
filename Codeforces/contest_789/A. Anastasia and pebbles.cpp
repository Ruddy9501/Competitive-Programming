/*
2017-03-29 19:11:29
https://codeforces.com/contest/789/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long a, b, n, m;
int can;
 
int main(){
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
    	 cin >> a;
    	 can += 1ll*(a / m) + 1ll*(a % m != 0);
    }   
 
    cout << 1ll*(can/2ll + (can%2ll != 0)) << "\n"; 
 
	return 0;
}