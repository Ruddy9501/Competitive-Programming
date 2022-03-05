/*
2017-08-03 21:35:14
https://codeforces.com/contest/837/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long a, b, tem;
long long sol;
vector <long long> v;
 
int main(){
    
 
    scanf ("%lld %lld", &a, &b);
 
    for (long long i = 2; i*i <= a; i++){
    	  while (a % i == 0){ 
    	     	v.push_back(i);
    	 	    a /= i;
    	 }
    }
 
    if (a > 1) v.push_back(a);
    
    long long m = 1;
    int n = (int)v.size();
    for (int i = 1; i <= n; i++){
    	 
    	 int p = -1;
    	 long long ma = 0;
    	 for (int j = 0; j < (int)v.size(); j++){
    	 	  if (ma <= b/(m*v[j])*(m*v[j])){
    	 	  	  p = j;
    	 	  	  ma = b/(m*v[j])*(m*v[j]);
    	 	  }
    	 }
         
         sol += (b-ma)/m;
         b = ma;
    	 m *= v[p]; //printf ("\n\n%d\n\n", v[p]);
    	 v.erase(p+v.begin());
 
    	 if (b == 1) break;
    }
    if (b >= 1) sol += b/m;
 
 
    printf ("%lld\n", sol);
 
	return 0;
}