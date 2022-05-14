/*
2015-11-19 07:05:14
https://codeforces.com/contest/592/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll n, x, y, gcd;
ll GCD(ll a, ll b){
   while (b){
          a%=b;
          swap(a,b);
   }
   return a;
}
 
int main(){
 
    cin >> n >> x >> y;
 
    if (x>y)swap(x,y);
 
    if (x==y || n < x){
        cout << "1/1"<<endl;
        return 0;
    }
 
    if( y > (n/(x/__gcd(x,y))) ){
        x--;
        cout << x/__gcd(x,n) << '/' << n/__gcd(x,n) << endl;
        return 0;
    }
 
    gcd = GCD(x,y);
    ll r = (y*(x/gcd));
    x = n/r*x + min(x-1,n-n/r*r);
 
     cout << x/GCD(n,x)<<"/"<<n/GCD(n,x)<<endl;
 
    return 0;
}