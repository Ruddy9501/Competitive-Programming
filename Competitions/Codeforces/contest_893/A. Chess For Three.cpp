/*
2017-11-23 18:10:54
https://codeforces.com/contest/893/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, a, b, c, x;
int main(){
 
    scanf ("%d", &n);
    int a = 1, b = 2, c = 3;
    for (int i = 0; i < n; i++){
         scanf ("%d", &x);
         if (x != a && x != b){
			// printf ("%d %d %d\n", x, a, b);
		     printf ("NO\n");
		     return 0;
		 }
		 
		 if (x == a) swap (b, c);
		 if (x == b) swap (a, c);
    }
    
    printf ("YES\n");
 
    return 0;
}