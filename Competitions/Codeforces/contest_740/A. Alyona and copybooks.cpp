/*
2016-11-23 20:19:17
https://codeforces.com/contest/740/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
long long n, a, b, c, cas, sol,  m;
 
int main(){
 
   scanf ("%lld%lld%lld%lld",&n,&a,&b,&c);
 
   sol = 1ll<<60;
   if (n%4ll==0ll)
       sol = 0ll;
 
   if (n%4ll == 3ll){
       sol = min(sol, min(a, min(3ll*c, b+c)));
   }
 
   if (n%4ll == 2ll)
       sol = min(sol, min(2ll*a, min(b, 2ll*c)));
 
   if (n%4ll == 1ll)
       sol = min(sol, min(3ll*a, min(c, a+b)));
 
   printf ("%lld\n", sol);
 
   return 0;
}