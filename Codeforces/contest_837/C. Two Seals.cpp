/*
2017-08-03 19:10:57
https://codeforces.com/contest/837/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int sol, n, a, b, X[1000], Y[1000];
 
int area(int i, int j){
	if (a >= X[i]+X[j] && b >= max(Y[i], Y[j]))
         return X[i]*Y[i] + X[j]*Y[j];
 
    if (a >= max(X[i], Y[j]) && b >= Y[i]+X[j])
        return X[i]*Y[i] + X[j]*Y[j];
    
    if (b >= X[i]+X[j] && a >= max(Y[i], Y[j]))
         return X[i]*Y[i] + X[j]*Y[j];
 
    if (b >= max(X[i], Y[j]) && a >= Y[i]+X[j])
        return X[i]*Y[i] + X[j]*Y[j];
   
    return 0;     
}
 
int main(){
    
    scanf ("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++)
    	 scanf ("%d %d", &X[i], &Y[i]); 
    
    for (int i = 0; i < n; i++){
    	 for (int j = 0; j < n; j++){
              if (i == j) continue;
              
              sol = max(sol, area(i, j));
              sol = max(sol, area(j, i));
 
              swap (X[i], Y[i]);  
              swap (X[j], Y[j]);  
 
              sol = max(sol, area(i, j));
              sol = max(sol, area(j, i));
 
    	 }
    }
 
    printf ("%d\n", sol);
 
	return 0;
}