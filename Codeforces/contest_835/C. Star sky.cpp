/*
2017-07-31 18:21:14
https://codeforces.com/contest/835/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, q, c, x, y, s, t, x_, y_;
int S[15][105][105];
 
int main(){
    
    scanf ("%d%d%d", &n, &q, &c);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d%d%d", &x, &y, &s);
    	 for (int j = 0; j <= 10; j++){
    	 	  S[j][x][y] += (s+j)%(c+1);
    	 }
    }
    
	for (int t = 0; t <= 10; t++){
		 for (int i = 1; i <= 100; i++){
		 	  for (int j = 1; j <= 100; j++){
		 	  	   S[t][i][j] = S[t][i][j] + S[t][i-1][j] + S[t][i][j-1] - S[t][i-1][j-1];
		 	  }
		 }
	}
 
    while (q--){
           scanf ("%d%d%d%d%d", &t, &x_, &y_, &x, &y);
           t %= (c+1); 
           int sol = S[t][x][y] + S[t][x_-1][y_-1] - S[t][x][y_-1] - S[t][x_-1][y];
           printf ("%d\n", sol); 	
           
    }  
 
	return 0;
}