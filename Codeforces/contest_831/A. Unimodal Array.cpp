/*
2017-07-13 18:12:55
https://codeforces.com/contest/831/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
int n;
int A[1000];
int main(){
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    	 cin >> A[i];
 
    
    int p = 1; 
    while (p < n && A[p] < A[p+1]) p++;
    while (p < n && A[p] == A[p+1]) p++;
    while (p < n && A[p] > A[p+1]) p++;
 
    if (p == n) printf ("YES\n");
     else printf ("NO\n");
 
	return 0;
}