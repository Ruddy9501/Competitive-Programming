/*
2017-07-25 17:16:44
https://codeforces.com/contest/832/problem/B
*/
#include <bits/stdc++.h>
 
 
using namespace std;
const int RAN = 1e5+5;
 
int k, a, b, con;
int F[RAN], F1[RAN];
char A[RAN], B[RAN], BB[RAN];
bool M[30], sol;
 
bool ok(char a, char b){
	 if (a == b) return true;
	 if (a == '?' && M[b-'a']) return true;
	 if (b == '?' && M[a-'a']) return true;
	 return false;
}
 
bool solve(int la, int lb){
	 int ini = 0;
	 
	 while (B[ini] != '*' && ini < lb  && ini < la && ok(B[ini], A[ini]))
	 	    ini++;
       
     
     int bb = ini;
     if (B[ini] == '*'){
     	 bb++;
     	 while (la-ini > lb - bb && ini < la && !M[A[ini]-'a']) ini++;
     }
 
     while (bb < lb && ini < la && ok(B[bb], A[ini])) 
	 	    ini++, bb++;
     
   // printf ("%d %d\n", ini, bb);
    if (ini >= la && bb >= lb) 
	    return true;
	  	
	return false;
}
 
int main (){
    
    scanf ("%s", A);
    scanf ("%s", B);
    int la = strlen (A);
    int lb = strlen (B);
 
    for (int i = 0; i < la; i++) M[A[i]-'a'] = true;
 
    int cas;scanf ("%d", &cas);
    while (cas--){
    	   scanf ("%s", A);
    	   la = strlen (A);
    	   
    	   if (solve(la, lb)) printf ("YES\n");
    	    else printf ("NO\n");
    } 
    
    return 0;
}