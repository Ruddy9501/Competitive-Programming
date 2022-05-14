/*
2017-08-04 17:49:38
https://codeforces.com/contest/837/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
struct tres{
       int cero, dos, cinco;
}A[205];
 
 
int n, k, sol;
long long a;
int Dp5[205][205*64+5];
int Dp2[205][205*64+5];
bool M[205][205*64+5];
 
int main(){
 
    scanf ("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
    	 scanf ("%lld", &a);
    	 while (a%10 == 0){
    	 	    A[i].cero++;
    	 	    a/=10;
    	 }
 
    	 while (a%2 == 0){
    	 	    A[i].dos++;
    	 	    a /= 2;
    	 }
 
    	 while (a%5 == 0){
    	 	    A[i].cinco++;
    	 	    a /= 5;
    	 }
         //printf ("%d %d %d\n", A[i].cero, A[i].cinco, A[i].dos);
    }  
    
    //M[0][0] = true;
    for (int l = 1; l <= n; l++) {
 
    int s = A[l].cero; 	 
    for (int i = k-1; i >= 1; i--){
    	 for (int j = 200*64; j >= 0; j--){
    	 	  if (M[i][j]){
                  
 
                     if (A[l].dos){
                     	 Dp2[i+1][j+s] = max (Dp2[i+1][j+s], Dp2[i][j] + A[l].dos);
                     	 M[i+1][j+s] = true;
                     }
 
                     if (A[l].cinco){
                     	 Dp5[i+1][j+s] = max (Dp5[i+1][j+s], Dp5[i][j] + A[l].cinco);
                     	 M[i+1][j+s] = true;
                     }
 
                                       
	                  if (Dp5[i][j] > A[l].dos){
	                  	  Dp5[i+1][j + A[l].dos + s] = max(Dp5[i][j] - A[l].dos, Dp5[i+1][j + A[l].dos + s]);
	                  	  M[i+1][j + A[l].dos + s] = true;
	                  }
	                   else{
                          Dp2[i+1][j + Dp5[i][j] + s] = max(A[l].dos - Dp5[i][j], Dp2[i+1][j + Dp5[i][j] + s]);
                          M[i+1][j+ Dp5[i][j]+ s] = true;
	                  }
	                              
                 
	                  if (Dp2[i][j] > A[l].cinco){
	                  	   Dp2[i+1][j + A[l].cinco + s] = max ( Dp2[i][j] - A[l].cinco,  Dp2[i+1][j + A[l].cinco + s]);
		                   M[i+1][j+ A[l].cinco + s]  = true;
	                  }	 
	                  else{
	                       Dp5[i+1][j+ Dp2[i][j] + s] = max(A[l].cinco - Dp2[i][j], Dp5[i+1][j+ Dp2[i][j] + s]);
	                       M[i+1][j+ Dp2[i][j] + s] = true;
		              }
    	 	    }
    	 } 
    }
 
    Dp5[1][A[l].cero] = max(A[l].cinco, Dp5[1][A[l].cero]);
    Dp2[1][A[l].cero] = max(A[l].dos, Dp2[1][A[l].cero]);
    M[1][A[l].cero] = true;
}
 
    
    for (int i = 1; i <= k; i++)
         for (int j = 0; j <= 64*200; j++)
            if (M[i][j])
             	 sol = max (sol, j); 
 
    printf ("%d\n", sol);
 
	return 0;
}