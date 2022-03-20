/*
2017-10-24 23:54:53
https://codeforces.com/contest/883/problem/H
*/
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 4e5 + 5;
int n, f[MAX];
char a[MAX];
vector <char> v, even, odd;
 
int main() {
	scanf("%d%s", &n, a + 1);
 
	for(int i = 1; i <= n; i++) {
		if(f[a[i]] == 0)
			v.push_back(a[i]);
 
		f[a[i]]++;
	}
 
	for(char c : v) {
		while(f[c] >= 2) {
			even.push_back(c);
			f[c] -= 2;
		}
 
		if(f[c] > 0)
			odd.push_back(c);
	}
 
	if(odd.empty()) {
		printf("1\n");
		for(char c : even)
			printf("%c", c);
 
		for(int i = even.size() - 1; i >= 0; i--)
			printf("%c", even[i]);
		printf("\n");
 
		return 0;
	}
 
	while((int) even.size() % (int) odd.size() != 0) {
		char c = even.back();
		even.pop_back();
		odd.push_back(c);
		odd.push_back(c);
	}
 
	//printf("%d %d\n", (int) even.size(), (int) odd.size());
 
	int d = (int) even.size() / (int) odd.size();
 
	vector <string> ans;
 
	int i = 0, j = 0;
 
	while(j < (int) odd.size()) {
		string w = "";
		for(int k = i; k < i + d; k++)
			w += even[k];
 
		w += odd[j];
 
		for(int k = i + d - 1; k >= i; k--)
			w += even[k];
 
		ans.push_back(w);
 
		i += d;
		j++;
	}
 
	printf("%d\n", (int) ans.size());
 
	for(string o : ans)
		printf("%s ", o.c_str());
	printf("\n");
	return 0;
}