#include <bits/stdc++.h>

using namespace std;

int n;
char a[3005][3005];
char s[10000];
bool m[3005][3005];
queue <pair<int, int> > Q, Q1;

int main(){
	
	scanf ("%d", &n);
	
	for (int i = 1; i <= n; i++)
	     fill (a[i], a[i]+n+1, CHAR_MAX);
	     
	     
	for (int i = 1; i <= n; i++)
	     scanf ("%s", a[i]+1);
	
	Q.push ({1, 1});
	for (int i = 0; i < 10000; i++) s[i] = CHAR_MAX;
	
	int p = 0;
	while (p <= n){
		
	       while (!Q.empty()){
		         int x = Q.front().first;
		         int y = Q.front().second;
		         Q.pop();
		         if (s[p] > a[x][y]){
		             s[p] = a[x][y];
		             while (!Q1.empty()) Q1.pop();
				 }
		           
		         if (s[p] == a[x][y] && !m[x][y]){
					 m[x][y] = true;
					 if (x < n && y < n) Q1.push ({x+1, y+1});           
					 if (x < n) Q1.push ({x+1, y});
				}           
		   }
		   
		   while (!Q1.empty()){
		          Q.push (Q1.front());
		          Q1.pop();
		   }
		     
		   p++;
	}
	
	for (int i = 0; i < n; i++) printf ("%c", s[i]);
	printf ("\n");
	
    return 0;	
}
