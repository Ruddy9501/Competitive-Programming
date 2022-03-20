/*
2017-11-23 18:28:38
https://codeforces.com/contest/893/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5 + 5;
const int oo = INT_MAX;
int n, m, id[MAX], ran[MAX];
long long sol, a[MAX], s[MAX];
 
int find_set (int x){
    if (x == id[x]) return x;
    return id[x] = find_set(id[x]); 
}
 
void joind_set (int x, int y){
     if (ran[x] < ran[y])
         swap (x, y);
     
     ran[x] += ran[y];
     id[y] = x;     
}
 
int main(){
    
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%lld", &a[i]);
         ran[i] = 1, id[i] = i;
         s[i] = oo;
    }
    
    for (int i = 0; i < m; i++){
	    int x, y;
	    scanf ("%d%d",&x, &y);
	    x = find_set (x);
	    y = find_set (y);
	    if (x != y) joind_set (x, y);
	}
    		
	for (int i = 1; i <= n; i++){
	     int x = find_set (i);
	     s[x] = min (s[x], a[i]);
	}
 
	for (int i = 1; i <= n; i++) 
	     if (s[i] != oo) sol += s[i];
	
	printf ("%lld\n", sol);
    
    
    return 0;
}