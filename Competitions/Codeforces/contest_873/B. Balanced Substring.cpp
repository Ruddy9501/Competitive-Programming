/*
2017-10-12 17:23:20
https://codeforces.com/contest/873/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
int n, U[2*RAN];
char A[RAN];
 
int main(){
    
    scanf ("%d", &n);
    scanf ("%s", A+1);
    
    fill (U, U+2*RAN, -1);
    
    int can = 0, sol = 0;
    for (int i = 1; i <= n; i++){
         if (A[i] == '1') can++;
         	else can--;
 
         if (can == 0) sol = max (sol, i);
          else{
 
          	if (U[RAN+can] != -1) sol = max (sol, i-U[RAN+can]);
          	if (U[RAN+can] == -1) U[RAN+can] = i;
 
          }
 
         // printf ("i: %d sol: %d can: %d\n", i, sol, can);
 
    }
    
    printf ("%d\n", sol);
 
	return 0;
}