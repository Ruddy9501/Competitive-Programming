/*
2017-03-23 19:09:00
https://codeforces.com/contest/787/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e6;
int n, m, k, g, A[RAN];
bool M[RAN];
 
int main (){
 
 
    scanf ("%d%d",&n, &m);
    bool sol = true;
    for (int i = 1; i <= m; i++){
    	 
    	 scanf ("%d", &k);
    	 fill (M, M+n*2+1, false); 
    	 bool mar = false;
 
    	 for (int j = 1; j <= k; j++){
    	 	  scanf ("%d", &g);
    	 	 
    	 	  if (A[g+n+1] == i) continue;
    	 	  A[g+n+1] = i;
    	 	   g = abs(g);
    	 	  if (M[g]) mar = true;
    	      M[g] = true;
    	 }
         //cout << mar << "\n";
    	 if (!mar) sol = false;
    }
    
    if (sol) printf ("NO\n");
     else printf ("YES\n");
 
	return 0;
}