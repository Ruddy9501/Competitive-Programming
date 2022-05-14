/*
2016-11-15 19:50:18
https://codeforces.com/contest/734/problem/B
*/
#include <iostream>
 
using namespace std;
char A[1000000];
int main(){
    long long a,sol = 0ll, b, c, d;
 
    cin >> a >> b >> c >> d;
 
    long long m = min(a, min(c, d));
 
    sol = m*256ll;
 
    a -= m;
 
    if (a > 0){
        sol += min(a, b) * 32ll;
    }
 
    cout << sol << "\n";
 
    return 0;
}