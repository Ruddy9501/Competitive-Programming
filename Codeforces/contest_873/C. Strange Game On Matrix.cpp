/*
2017-10-12 17:50:23
https://codeforces.com/contest/873/problem/C
*/
#include <bits/stdc++.h>
 
 
using namespace std;
 
int n, m, k, A[1005][1005];
 
int main(){
    
    scanf ("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
    	 for (int j = 1; j <= m; j++)
              scanf ("%d", &A[i][j]);
 
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= m; i++){
    	 int ant = 0, a1 = 0, a2 = INT_MAX;
    	 for (int j = 1; j <= n; j++){
    	 	  if (A[j][i] == 1){
    	 	  	  int can = 0;
    	 	  	  for (int l = j; l <= n && l < j+k; l++)
    	 	  	  	   if (A[l][i]) can++;
    	 	  	  if (can > a1){
    	 	  	      a1 = can;
    	 	  	      a2 = ant;
    	 	  	  }
    	 	  	  else
    	 	  	   	  if (can == a1)
    	 	  	          a2 = min (a2, ant);
    	 	  	  ant++;        	
    	 	  }
    	 }
 
    	 if (a1 != 0)
    	 	 s1 += a1, s2 += a2;
    }      
 
    printf ("%d %d\n", s1, s2);
 
    return 0;
}