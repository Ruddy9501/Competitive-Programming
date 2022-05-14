/*
2017-09-22 21:18:47
https://codeforces.com/contest/847/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5 + 5;
int n;
char a[MAX];
 
bool f(int k) {
	queue <int> q;
 
	for(int i = 1; i <= n; i++)
		if(a[i] == '*') {
			//printf("%d\n", i);
			q.push(i);
		}
 
	for(int i = 1; i <= n; i++) {
		if(q.empty())
			break;
 
		if(a[i] == 'P') {
			int pos = q.front();
 
			if(pos < i) {
				if(i - pos > k)
					return 0;
 
				int d = i - pos;
 
				while(!q.empty() && q.front() < i)
					q.pop();
 
				while(!q.empty() && (q.front() - i + 2 * d <= k || (q.front() - i) * 2 + d <= k))
					q.pop();
			}
 
			else {
				while(!q.empty() && q.front() - i <= k)
					q.pop();
			}
		}
	}
 
	if(!q.empty())
		return 0;
 
	return 1;
}
 
int g(int k) {
	queue <int> q;
 
	for(int i = n; i > 0; i--)
		if(a[i] == '*') {
			//printf("%d\n", i);
			q.push(i);
		}
 
	for(int i = n; i > 0; i--) {
		if(q.empty())
			break;
 
		if(a[i] == 'P') {
			int pos = q.front();
 
			if(pos > i) {
				if(pos - i > k)
					return 0;
 
				int d = pos - i;
 
				while(!q.empty() && q.front() > i)
					q.pop();
 
				while(!q.empty() && (i - q.front() + 2 * d <= k || (i - q.front()) * 2 + d <= k))
					q.pop();
			}
 
			else {
				while(!q.empty() && i - q.front() <= k)
					q.pop();
			}
		}
	}
 
	if(!q.empty())
		return 0;
 
	return 1;
}
 
int main() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	
	int st = 0, nd = 1e9, ans = 1e9;
 
	while(st <= nd) {
		int mid = (st + nd) >> 1;
 
		if(f(mid) || g(mid)) {
			ans = min(ans, mid);
			nd = mid - 1;
		}
 
		else st = mid + 1;
	}
 
	printf("%d\n", ans);
	return 0;
}