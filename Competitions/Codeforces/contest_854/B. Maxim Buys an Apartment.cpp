/*
2017-09-06 16:21:35
https://codeforces.com/contest/854/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, k;
 
int main(){
 
    scanf ("%d%d", &n, &k);
    if (n == k || k == 0){
    	printf ("0 0\n");
    	return 0;
    }
 
    int d = n/3;
    int r = n%3;
 
    int can = min(k, d) * 2;
    if (r == 2 && k > d) can++;
    can = min(can, n-k);
 
	printf ("1 %d\n", can);
 
	return 0;
}