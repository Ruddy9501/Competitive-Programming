/*
2017-10-27 17:08:32
https://codeforces.com/contest/884/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int T = 86400;
int n, t;
 
int main(){
   
    scanf ("%d %d", &n, &t);
    for (int i = 1; i <= n; i++){
    	 int a;scanf ("%d", &a);
    	 t -= (T-a);
    	 if (t <= 0){
    	 	 printf ("%d\n", i);
    	 	 break;
    	 }
    }
 
	return 0;
}