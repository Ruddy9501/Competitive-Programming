/*
2018-03-17 03:51:23
https://codeforces.com/contest/476/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
char a[100], b[100];
int x, y;
int main(){
 
    scanf ("%s", a);
    scanf ("%s", b);
 
    int la = strlen (a);
    int lb = strlen (b);
 
    for (int i = 0; i < la; i++) 
    	 x += (a[i] == '+'), y += (a[i] == '-');
 
    for (int i = 0; i < lb; i++)
         x -= (b[i] == '+'), y -= (b[i] == '-');
 
    if (x < 0 || y < 0)
        printf ("%.10lf\n", 0.0);
     else{
     	int p = 1, f = 1, f1 = 1, f2 = 1;
     	for (int i = 1; i <= x+y; i++) p *= 2, f *= i;
 
        for (int i = 1; i <= x; i++) f1 *= i;
        for (int i = 1; i <= y; i++) f2 *= i;
        
        //printf ("%d %d\n", x, y); 
        printf ("%.10lf\n", 1.0 * f/f1/f2/p);		
     }         	
 
	return 0;
}