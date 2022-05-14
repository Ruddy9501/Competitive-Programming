/*
2017-07-13 18:23:02
https://codeforces.com/contest/831/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
char A[100], B[100], T[100000];
 
int main(){
 
    scanf ("%s", A);
    scanf ("%s", B);
    scanf ("%s", T);
 
    int l = strlen (T);
    for (int i = 0; i < l; i++){
    	 bool mar = true;
    	 for (int j = 0; j < 26; j++){
    	 	  if (A[j] == T[i]){
    	 	  	  printf ("%c", B[j]);
    	 	  	  mar = false;
    	 	  	  break;
    	 	  }
    	 	  if (A[j]-'a' == T[i]-'A'){
    	 	  	  printf ("%c", B[j]-'a'+'A');
    	 	  	  mar = false;
    	 	  	  break;
    	 	  }
    	 }
    	 if (mar) printf ("%c", T[i]);
    }
 
    printf ("\n");
 
	return 0;
}