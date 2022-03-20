/*
2017-11-17 17:41:06
https://codeforces.com/contest/892/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5 + 5;
int n;
long long a[MAX], b[MAX], tot;
vector <long long> v; 
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf ("%lld", &b[i]);
    
    for (int i = 0; i < n; i++){
	     tot += a[i];
	     v.push_back (b[i]);
	}
    
    sort (v.begin(), v.end());
    
    if(v[n-1] + v[n-2] >= tot) printf ("YES\n");
     else printf ("NO\n");
    
    return 0; 
}