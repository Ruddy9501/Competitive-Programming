/*
2017-11-09 18:22:38
https://codeforces.com/contest/888/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, u, l, r, d;
char car;
 
int main(){
	
	scanf ("%d\n", &n);
	for (int i = 0; i < n; i++){
	     scanf ("%c", &car);
	     if (car == 'U') u++;
	     if (car == 'D') d++;
	     if (car == 'L') l++;
	     if (car == 'R') r++;
	}
	
	printf ("%d\n", 2*min(u , d) + 2*min(l, r));
	
    return 0;	
}