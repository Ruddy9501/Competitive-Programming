/*
2017-08-14 17:37:32
https://codeforces.com/contest/837/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, r, b, g;
char A[1000][1000], B[100];
 
int main(){
    
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    	 scanf ("%s", A[i]);
 
    for (int i = 0; i < n; i++)
    	 for (int j = 0; j < m; j++){
    	 	  if (A[i][j] != 'R' && A[i][j] != 'G' && A[i][j] != 'B'){
    	 	  	  printf ("NO\n");
    	 	  	  return 0;
    	 	  }
 
    	 	  if (A[i][j] == 'R')r++;
    	 	  if (A[i][j] == 'G')g++;
    	 	  if (A[i][j] == 'B')b++;
    	 }
    
 
 
    if (!r || !b || !g){
    	printf ("NO\n");
    	return 0; 
    } 
 
    //filas	 
    bool mm = false; 	 
    if ( n%3 == 0) { 
    	mm = true;
	    B[0] = A[n/3-1][0];
	    B[1] = A[2*n/3-1][0];
	    B[2] = A[n-1][0]; 
		for (int i = 0; i < n; i++){
			 for (int j = 0; j < m; j++){
		          if (A[i][j] != B[i/(n/3)])
		          	  mm = false;
			 }
		} 	 
    }
 
    if (mm){
    	printf ("YES\n");
    	return 0; 
    } 
    
    if ( m%3 == 0) { 
    	mm = true;
	    B[0] = A[0][m/3-1];
	    B[1] = A[0][2*m/3-1];
	    B[2] = A[0][m-1]; 
		for (int i = 0; i < n; i++){
			 for (int j = 0; j < m; j++){
		          if (A[i][j] != B[j/(m/3)])
		          	  mm = false;
			 }
		} 	 
    }
    
    if (mm){
    	printf ("YES\n");
    	return 0; 
    }  
    
    printf ("NO\n");
 
	return 0;
}