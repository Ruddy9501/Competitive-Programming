/*
2017-08-03 16:12:30
https://codeforces.com/contest/835/problem/E
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int n, x, y, mask, bit;
 
 
int pregunta(vector <int> v){
	printf ("? %d", (int)v.size());
	for (int i = 0; i < (int)v.size(); i++)
	     printf (" %d", v[i]);
	printf ("\n");
	fflush (stdout); 
	int z; scanf ("%d", &z);
	return z;      
}
 
int bus(int bit){
	vector <int> a;
    for (int i = 1; i <= n; i++)
    	 if (i & (1<<bit))
    	     a.push_back (i); 
    int ini = 1, fin = a.size();
    int sol= 0;
    while (ini <= fin){
    	   int piv = (ini+fin)/2;
    	   vector <int> b;
    	   for (int i = ini; i <= piv; i++)
                b.push_back (a[i-1]);
    	   int r = pregunta (b);
    	   if (r == y || r == (x^y))
    	       fin = piv-1, sol = piv;
    	    else ini = piv+1;    
    	   //printf ("-----inni: %d fin: %d\n", ini, fin); 
    } //printf ("%d\n", a[sol]);
    return a[sol-1];	      
}
 
int main(){
    
    scanf ("%d%d%d", &n, &x, &y);
    for (int i = 0; i < 10; i++){
    	 vector <int> v;
    	 for (int j = 1; j <= n; j++)
    	 	  if (j & (1<<i))
    	 	  	  v.push_back(j);
    	 if ((int)v.size() == 0) continue;
    	 int a = pregunta(v);  	  	
         if (a == y || a == (x^y)){
             mask |= 1<<i;
             bit = i; 
         } 
    } 
 
   // printf ("%d --- - -\n", bit);
    	         
    int sol1 = bus(bit);
    int sol2 = sol1 ^ mask;
    if (sol1 > sol2) swap(sol1, sol2);
 
    printf ("! %d %d\n", sol1, sol2);
    fflush (stdout);
 
	return 0;
}