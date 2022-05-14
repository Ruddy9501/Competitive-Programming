/*
2017-11-28 18:33:22
https://codeforces.com/contest/890/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5 + 5;
int n, a, sol, c[MAX];
multiset <int> s; 
 
 
int main(){
    
    
    scanf ("%d", &n);
    
  //  for (int i = 0; i <= n; i++) s.insert (i);
    
    for (int i = 1; i <= n; i++) {
	     scanf ("%d", &a);
	     c[a]++; 
	}
	
	for (int i = 0; i <= MAX; i++) 
	     if (c[i]) sol += c[i]-1;
	
	printf ("%d\n", sol+1);
    
    return 0;
}