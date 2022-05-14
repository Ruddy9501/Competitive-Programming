/*
2017-10-24 23:37:38
https://codeforces.com/contest/883/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, can, c[30];
bool l[30];
char a[1000], b[1000];
 
int main(){
 
    scanf ("%d", &n);
    scanf ("%s", a);
    for (int i = 0; i < n; i++)
    	 if (a[i] != '*')
    	 	 l[a[i]-'a'] = true;
 
 
    scanf ("%d", &m);
    for (int i = 0 ; i < m; i++){
         scanf ("%s", b); //printf ("%s\n", b);
         
         bool m = false; 
         for (int j = 0; j < n; j++)
         	  if ((a[j] != b[j] && a[j] != '*') || (l[b[j]-'a'] && a[j] == '*'))
         	  	  m = true;
 
         if (m) continue; 	  	
 
         vector <int> v;
         for (int j = 0; j < n; j++){
             // printf ("%c %c\n", a[j], b[j]);
         	  if (a[j] != '*' || l[b[j]-'a']) continue;
         
              v.push_back (b[j]-'a');
             // printf ("%c", b[j]);
         } 
 
         sort (v.begin(), v.end());
         auto it = unique (v.begin(), v.end());
         v.erase (it, v.end());
 
         if (v.empty()) continue;
 
         can++;
         for (auto it : v)
         	  c[it]++;
    } 
    
    int sol = 0;
    for (int i = 0; i < 26; i++)
         if (c[i] == can && can) 
             sol++;
 
    printf("%d\n", sol);          
 
	return 0;
}