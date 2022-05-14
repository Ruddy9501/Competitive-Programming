/*
2016-04-27 17:36:41
https://codeforces.com/contest/522/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
int n, id, sol;
string a, b, c;
map <string, int> mp;
vector <int> g[1005];
 
void dfs(int u, int p = -1, int dt = 0) {
	sol = max(sol, dt);
	for(int v : g[u]) {
		if(v != p)
			dfs(v, u, dt + 1);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> a >> c >> b;
		
		for(int j = 0; j < a.size(); j++)
			if(a[j] >= 'A' && a[j] <= 'Z')
				a[j] = a[j] - 'A' + 'a';
				
		for(int j = 0; j < b.size(); j++)
			if(b[j] >= 'A' && b[j] <= 'Z')
				b[j] = b[j] - 'A' + 'a';
		
		if(!mp.count(a))
			mp[a] = ++id;
			
		if(!mp.count(b))
			mp[b] = ++id;
			
		g[mp[b]].push_back(mp[a]);
		
		//cout << a << " " << b << '\n';
		//cout << mp[a] << " " << mp[b] << '\n';
	}
	
	for(int i = 1; i <= id; i++) {
		dfs(i);
	}
			
	cout << sol + 1 << '\n';
}