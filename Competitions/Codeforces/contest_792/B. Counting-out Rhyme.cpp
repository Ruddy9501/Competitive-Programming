/*
2017-04-06 20:13:09
https://codeforces.com/contest/792/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e3 + 5;
 
int n, k, a;
vector <int> v;
 
int main(){
     
    scanf ("%d %d", &n, &k);
    
    for (int i = 1; i <= n; i++) v.push_back(i);  
    
    int pos = 1;
    for (int i = 1; i <= k; i++){
         scanf ("%d", &a); 
         a = a % (int)v.size();
         if (a <= (int)v.size()-pos)
             pos += a;
          else
             pos = a - ((int)v.size()-pos);
         
         if (i == k) printf ("%d\n", v[pos-1]);
           else printf ("%d ", v[pos-1]);
         
         v.erase (v.begin() + pos-1);
          
          
    }
 
	return 0;
}