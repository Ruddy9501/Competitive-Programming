/*
2017-10-12 03:01:03
https://codeforces.com/contest/867/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n;
char A[105];
 
int main(){
    
    scanf ("%d", &n);
    scanf ("%s", A);
     
    int a = 0, b = 0; 
    for (int i = 1; i < n; i++){
         if (A[i-1] == 'S' && A[i] == 'F') a++;
         if (A[i-1] == 'F' && A[i] == 'S') b++;
    }
 
    if (a > b) printf ("YES\n");
     else printf ("NO\n");
 
	return 0;
}