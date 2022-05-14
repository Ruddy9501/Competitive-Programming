/*
2017-07-12 03:18:57
https://codeforces.com/contest/828/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long 
 
int sol, a, b, n, x, a1;
int main(){
 
    scanf ("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++){
    	 scanf ("%d", &x);
    	 if (x == 2){
    	 	 if (b > 0) b--;
    	 	  else sol+=2;
    	 }
    	 else{
    	 	 if (a > 0){ 
                 a--; 
             }
    	 	  else {
    	 	  	 if (b > 0) b--, a1++;
    	 	  	  else {
                    if (a1 > 0) a1--;
                     else sol++;}
    	 	  	} 
    	 }
    	// cout << a << " " << b << " " << sol <<"\n";
    }
    
    printf ("%d\n", sol);
 
	return 0;
}