/*
2017-11-09 19:53:05
https://codeforces.com/contest/888/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
char a[1000005];
int sol, b[30], s[30]; 
 
int main(){
	
	scanf ("%s", a+1);
	int l = strlen (a+1);
	for (int i = 1; i <= l; i++){
		if (b[a[i]-'a'] != 0)
		    s[a[i]-'a'] = max (s[a[i]-'a'], i - b[a[i]-'a']); 
		 else
		    s[a[i]-'a'] = i;   
	    b[a[i]-'a'] = i; 
	}
	
	int sol = l/2 + 1;
	for (int i = 0; i < 26; i++)
	     if (s[i] != 0)sol = min(sol, max(s[i], l-b[i]+1));
	//printf ("%d\n", s[0]);
	
	printf ("%d\n", sol);
	
    return 0;	
}