/*
2017-11-09 18:17:27
https://codeforces.com/contest/888/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, sol, a[100000];
 
int main(){
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
	n--;
	for (int i = 1; i < n; i++){
	     if (a[i] > a[i-1] && a[i] > a[i+1]) sol++;
	     if (a[i] < a[i-1] && a[i] < a[i+1]) sol++;
	}
	
	printf ("%d\n", sol);
	
    return 0;	
}