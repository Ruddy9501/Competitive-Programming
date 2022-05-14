/*
2017-10-24 20:23:23
https://codeforces.com/contest/883/problem/M
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int x, y, a, b;
 
int main(){
    
    scanf ("%d%d", &a, &b);
    scanf ("%d%d", &x, &y);
     
    printf ("%d\n", 2 * (max(2, abs(a-x)+1) + max (2, abs(b-y)+1))); 
 
	return 0;
} 