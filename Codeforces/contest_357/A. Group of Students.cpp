/*
2016-04-27 17:04:15
https://codeforces.com/contest/357/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, a[105], x, y;
 
bool ok(int a, int b) {
	return a >= x && a <= y && b >= x && b <= y;	
}
 
int main() {
	scanf("%d", &n);
	
	int s2 = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s2 += a[i];
	}
	
	scanf("%d%d", &x, &y);
 
	for(int i = 1; i <= n + 1; i++) {
		int s1 = 0, s2 = 0;
		for(int j = 1; j < i; j++)
			s1 += a[j];
			
		for(int j = i; j <= n; j++)
			s2 += a[j];
			
		if(ok(s1, s2)) {
			printf("%d\n", i);
			return 0;
		}
	}
	
	printf("0\n");
	return 0;
}