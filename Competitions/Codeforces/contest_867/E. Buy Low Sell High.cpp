/*
2017-10-12 19:39:32
https://codeforces.com/contest/867/problem/E
*/
#include <bits/stdc++.h>
 
 
using namespace std;
 
const int MAX = 3e5 + 5;
int n , a;
long long sol;
multiset <int> s;
 
int main (){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	   scanf ("%d", &a);
         if (!s.empty() && a > *s.begin()){
             sol += a-*s.begin();
             s.erase (s.begin());
             s.insert (a);
         }
         s.insert (a);
    }
    
    printf ("%lld\n", sol);
 
	return 0;
}