/*
2017-09-22 18:14:47
https://codeforces.com/contest/847/problem/G
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, c[10];
char a[10];
 
int main() {
	scanf("%d", &n);
 
	for(int i = 1; i <= n; i++) {
		scanf("%s", a + 1);
 
		for(int j = 1; j <= 7; j++)
			if(a[j] == '1')
				c[j]++;
	}
 
	int sol = 0;
	for(int i = 1; i <= 7; i++)
		sol = max(sol, c[i]);
 
	printf("%d\n", sol);
	return 0;
}