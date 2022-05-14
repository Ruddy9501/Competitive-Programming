/*
2017-09-23 16:12:34
https://codeforces.com/contest/854/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e6 + 5;
const long long oo = 1ll<<60;
int n, m, x, y, t, k;
bool M[RAN];
long long c, tot, C[RAN], sol = oo, X[RAN], Y[RAN];
 
struct par{
       int x, y;
       long long c;    
};
 
vector <par> v[RAN];
 
int main(){
 
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++){
    	 scanf ("%d%d%d%lld", &t, &x, &y, &c);
    	 v[t].push_back(par{x,y,c});
    }
 
    fill (M+1,M+n+1, false);
    int can = 0; 
    for (int i = 1; i < RAN; i++){
         for (int j = 0; j < (int)v[i].size(); j++){
              par a = v[i][j];
              if (a.x == 0) continue;
 
              if (!M[a.x]){
              	  M[a.x] = true;
              	  C[a.x] = a.c;
              	  tot += a.c;
              	  can++;
              }
              
              if (a.c < C[a.x]){
              	  tot = tot - C[a.x] + a.c;
              	  C[a.x] = a.c;
              }
         }
 
         if (can == n) X[i] = tot; 
    }
    
   // for (int i = 1; i <= 15; i++) printf ("%lld ", X[i]);
 
    //printf ("\n"); 	
 
    can = 0; tot = 0;
    fill (M+1, M+n+1, false); 
 
    for (int i = RAN-1; i > 0; i--){
         for (int j = 0; j < (int)v[i].size(); j++){
              par a = v[i][j];
              if (a.y == 0) continue;
 
              if (!M[a.y]){
              	  M[a.y] = true;
              	  C[a.y] = a.c;
              	  tot += a.c;
              	  can++;
              }
 
             //printf ("------ %d %d\n", i, a.x);
              
              if (a.c < C[a.y]){
              	  tot = tot - C[a.y] + a.c;
              	  C[a.y] = a.c;
              }
         }
 
         if (can == n) Y[i] = tot; 
         //printf ("%d ", can);
    } //printf ("\n\n");
 
   // for (int i = 1; i <= 15; i++) printf ("%lld ", Y[i]);
 
   // printf ("\n"); 
 
    for (int i = 1; i < RAN-k-2; i++){
    	 if (X[i] && Y[i+k+1])
    	 	 sol = min (sol, X[i] + Y[i+k+1]);
    }
 
    if (sol == oo) printf ("-1\n");
     else printf ("%lld\n", sol);
 
	return 0;
}