/*
2016-11-22 04:25:57
https://codeforces.com/contest/738/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2*1e5+5;
int A[RAN], n, m;
int main(){
     
    
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    	 scanf ("%d", &A[i]);
 
    int sol = 0;
    if (A[m] != 0) sol++;
    A[m] = 0;
 
    for (int i = 1; i <= n; i++){
        if (i == m) continue; 	
        if (A[i] == 0) A[i] = n;
    }
    
    sort (A+1,A+n+1); int max = 0;
    for (int i = 1, j = 1; j <= n; j++, i++){
    	 if (A[i] > max+1) {
    	 	i--; 
    	 	sol++;
    	 	max++;
    	 }
 
    	 if (A[i] == max+1) max++;
 
 
    }
 
    printf ("%d\n", sol);
 
	return 0;
}