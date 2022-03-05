/*
2017-07-31 18:57:57
https://codeforces.com/contest/835/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
char s[5005];
long long  S[5005][5005], A[5005];
bool P[5005][5005];
 
int main(){
 
    scanf ("%s", s);
    int la = strlen (s);
 
    for (int i = 0; i < la; i++)
    	 P[1][i] = true, S[1][i] = 1, A[1]++;
    
    for (int i = 1; i < la; i++)
         if (s[i-1] == s[i])
             P[2][i] = true, S[2][i] = 2, A[2]++;
    
    for (int i = 3; i <= la; i++){
         for (int j = i-1; j < la; j++){
         	  if (P[i-2][j-1] && s[j] == s[j-i+1])
         	  	  P[i][j] = true;
         }
    }
/*
    for (int i = 1; i <= la; i++)
    	 for (int j = 0; j < la; j++)
    	 	  if (j == la-1) printf ("%d\n", P[i][j]);
    	 	   else printf ("%d ", P[i][j]);
*/
    for (int i = 3; i <= la; i++){
    	 int t = i/2;
    	 for (int j = i-1; j < la; j++){
    	 	  if (!P[i][j]) continue;
    	 	 
    	 	  if (i%2){
    	 	  	  if (S[t][j] == S[t][j-t-1]){
    	 	  	  	  S[i][j] = S[t][j]+1;
    	 	  	  	  A[S[i][j]]++;
    	 	  	  }
    	 	  }
    	 	  else{
    	 	  	 if (S[t][j] == S[t][j-t]){
    	 	  	 	 S[i][j] = S[t][j]+1;
    	 	  	  	 A[S[i][j]]++;
    	 	  	 }
    	 	  }
 
    	 }
    }
 
    for (int i = la; i >= 1; i--)
    	 A[i] += A[i+1];
    
    for (int i = 1; i <= la; i++) 
    	 if (i == la) printf ("%lld\n", A[i]);
    	 else printf ("%lld ", A[i]);
 
	return 0;
    
}