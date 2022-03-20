/*
2017-11-28 18:29:02
https://codeforces.com/contest/890/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5 + 5;
int n, sol, a[MAX];
bool m[MAX];
 
int main(){
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
	     scanf ("%d", &a[i]);
	}
	
	for (int i = n; i > 0; i--){
	     if (!m[a[i]]) sol = a[i];
	     m[a[i]] = true;
	}
	
	printf ("%d\n", sol);
	
    return 0;	
}