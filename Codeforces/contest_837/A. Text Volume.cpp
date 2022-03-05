/*
2017-08-03 18:20:19
https://codeforces.com/contest/837/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int sol, n;
char A[1000];
 
int main(){
    scanf ("%d", &n);
    while (scanf ("%s", A) != EOF){
    	   int la = strlen (A);
    	   int a = 0;
    	   for (int i = 0; i < la; i++){
    	   	    if (A[i] >= 'A' && A[i] <= 'Z') a++;
    	   }
    	   sol = max (sol, a);
    }
 
    printf ("%d\n", sol);
 
	return 0;
}