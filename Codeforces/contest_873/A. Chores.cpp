/*
2017-10-12 17:10:08
https://codeforces.com/contest/873/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, k, x, sol, A[10000];
 
int main(){
 
    scanf ("%d %d %d", &n, &k, &x);
    for (int i = 0; i < n; i++){
    	 scanf ("%d", &A[i]);
    	 sol += A[i];
    }
    
    n--;
    for (int i = 0; i < k; i++, n--){
         if (A[n] > x){
         	 sol -= A[n];
         	 sol += x;
         }
    }
 
    printf ("%d\n", sol);
 
	return 0;
}