/*
2017-07-12 03:14:46
https://codeforces.com/contest/828/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, L[1000005];
 
typedef pair<int, int> par;
vector <par> v;
 
int main(){
 
    scanf ("%d %d", &n, &m);
	for (int i = 2; i <= n; i++){
		 if (i <= m){
		 	 v.push_back(par(1, i));
	         L[i] = L[1] + 1;
		 }
		 else{
		 	v.push_back(par(i-m, i));
		 	L[i] = L[i-m] + 1;
		 }
	}
 
	printf ("%d\n", L[n-1]+L[n]);
	for (int i = 0; i < n-1; i++)
		 printf ("%d %d\n", v[i].first, v[i].second); 
	
 
	return 0;