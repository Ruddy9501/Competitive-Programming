/*
2017-07-31 17:45:31
https://codeforces.com/contest/835/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int t,v1,v2,t1,t2;
 
int main(){
 
   scanf ("%d%d%d%d%d", &t, &v1, &v2, &t1, &t2);
   long long a = 2*t1, b = 2*t2;
   for (int i = 1; i <= t; i++){
   	    a = a + v1;
   	    b = b + v2;
   	    
   }
   
   //printf ("%lld %lld\n", a, b);
 
   if (a == b) printf ("Friendship\n");
   else if (a < b) printf ("First\n");
         else printf ("Second\n");
 
	return 0;
}