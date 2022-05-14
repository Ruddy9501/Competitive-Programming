/*
2017-03-30 01:36:48
https://codeforces.com/contest/789/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long ant, a, b, q, l, sol;
map <long long, bool> M;
int n;
 
int main(){
 
    cin >> b >> q >> l >> n; 
    for (int i = 1; i <= n; i++){
    	 cin >> a;
    	 M[a] = true;
    }
    
    ant = b+1; int con = 0;
    while (abs(b) <= l){
    	   con++;
    	   if (con == 1000000){
    	       if (sol > 100)
    	   	       cout << "inf\n";
    	   	    else cout << "0\n";
    	   	   return 0;
    	   }
    	   if (ant == b){
    	   	   if (M[b]) break;
    	   	   cout << "inf\n";
    	   	   return 0;
    	   }
 
    	   if (M[b] != true) sol++;
           
           ant = b; 
    	   b *= q;
    }
 
    cout << sol << "\n";
 
	return 0;
}