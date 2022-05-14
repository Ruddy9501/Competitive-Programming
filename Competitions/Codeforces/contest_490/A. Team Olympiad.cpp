/*
2016-04-27 16:30:35
https://codeforces.com/contest/490/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
int n;
vector <int> v[5];
 
int main() {
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		v[x].push_back(i);
	}
	
	int cnt = min(v[1].size(), min(v[2].size(), v[3].size()));
	
	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; i++) {
		printf("%d %d %d\n", v[1].back(), v[2].back(), v[3].back());
		v[1].pop_back();
		v[2].pop_back();
		v[3].pop_back();
	}
	
	return 0;
}