/*
2016-11-03 19:16:59
https://codeforces.com/contest/730/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, t;
 
int main() {
	scanf("%d", &t);
 
	while(t--) {
		scanf("%d", &n);
 
		if(n == 1) {
			printf("! 1 1\n");
			fflush(stdout);
			continue;
		}
 
		int min = 1, max = 2;
 
		if(n % 2 == 0) {
			printf("? 1 2\n");
			fflush(stdout);
 
			char c[10]; scanf("%s", c);
 
			if(c[0] == '>')
				swap(min, max);
		}
 
		else min = max = 1;
 
		int i = (n % 2 == 1) ? 3 : 4;
 
		for(; i <= n; i += 2) {
			printf("? %d %d\n", i - 1, i);
			fflush(stdout);
 
			char c[10]; scanf("%s", c);
 
			if(c[0] == '<') {
				if(i - 1 == min)
					c[0] = '=';
 
				else {
					printf("? %d %d\n", i - 1, min);
					fflush(stdout);
 
					scanf("%s", c);
				}
 
				if(c[0] == '<')
					min = i - 1;
 
				if(i == max)
					c[0] = '=';
 
				else {
					printf("? %d %d\n", i, max);
					fflush(stdout);
 
					scanf("%s", c);
				}
 
				if(c[0] == '>')
					max = i;
			}
 
			else {
				if(i - 1 == max)
					c[0] = '=';
 
				else {
					printf("? %d %d\n", i - 1, max);
					fflush(stdout);
 
					scanf("%s", c);
				}
 
				if(c[0] == '>')
					max = i - 1;
 
				if(i == min)
					c[0] = '=';
 
				else {
					printf("? %d %d\n", i, min);
					fflush(stdout);
 
					scanf("%s", c);
				}
 
				if(c[0] == '<')
					min = i;
			}
		}
 
		printf("! %d %d\n", min, max);
		fflush(stdout);
	}
 
	return 0;
}