/*
2017-08-29 18:35:30
https://codeforces.com/contest/842/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int sol, n;
double x, y, r, r1, d;
 
int main(){
    
    scanf ("%lf %lf", &r, &d);
    scanf ("%d", &n);
    while (n--){	
    	   scanf ("%lf %lf %lf", &x, &y, &r1);
    	   double dis = sqrt (x*x + y*y);
    	   if (dis-r1 >= r-d && dis+r1 <= r) sol++;
    }
    
    printf ("%d\n", sol);
 
	return 0;
}