/*
2016-04-27 16:45:18
https://codeforces.com/contest/448/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
int a, b, c, d, e, f, n;
 
int main() {
	scanf("%d%d%d", &a, &b, &c)	;
	scanf("%d%d%d", &d, &e, &f)	;
	
	int s1 = a + b + c;
	int s2 = d + e + f;
	
	int ans = s1 / 5 + (s1 % 5 > 0) + s2 / 10 + (s2 % 10 > 0);
	scanf("%d", &n);
	//printf("%d\n", ans);
	
	if(ans <= n)
		printf("YES\n");
		
	else printf("NO\n");
	
	return 0;
}