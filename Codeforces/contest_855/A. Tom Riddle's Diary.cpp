/*
2018-02-28 00:14:50
https://codeforces.com/contest/855/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
 
int n;
bool mar[10000];
string a[10000];
map <string, bool> m;
 
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++)
    	 cin >> a[i];
 
    for (int i = 1; i <= n; i++){
    	 if (m.count(a[i])) mar[i] = true;
    	  else mar[i] = false;
    	 m[a[i]] = true; 
    } 	  
 
    for (int i = 1; i <= n; i++){
    	 if (mar[i]) cout << "YES\n";
    	  else cout << "NO\n";
    }
 
	return 0;
}