/*
2016-11-04 16:31:46
https://codeforces.com/contest/730/problem/E
*/
#include <bits/stdc++.h>
#define RAN 1005
using namespace std;
 
int n, sol;
bool M[RAN];
struct par{
       int p, s, id;
       bool operator<(const par &R)const{
       	    if (p != R.p) return p > R.p;
       	    return id < R.id;
       }
 
}A[RAN];
 
int bus_pos(){
	sort (A+1, A+n+1);
	for (int i = n; i > 0; i--){
		 if (!M[A[i].id] && A[i].s >= 0)
		 	 return i;
	}
	return -1;
}
 
int bus_neg(){
    for (int i = 1; i <= n; i++){
		 if (!M[A[i].id] && A[i].s < 0)
		 	 return i;
	}
	return -1; 	
}	
 
int new_pos(int p, int id){
	sort (A+1, A+n+1);
	for (int i = 1; i <= n; i++){
		 if (A[i].id == id)
		     return abs(p-i); 
	}
	return 0;
}
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d %d", &A[i].p, &A[i].s);
    	 A[i].id = i;
    }
    
    bool mar = true;
    while (mar){
    	   int p = bus_pos();
    	  
           if (p == -1) 
           	   mar = false;
            else{
               M[A[p].id] = true;
               A[p].p += A[p].s;
               sol += new_pos(p, A[p].id);
            }
    }
 
    mar = true;
    while (mar){
    	   int p = bus_neg();
           if (p == -1) 
           	   mar = false;
            else{
               M[A[p].id] = true;
               A[p].p += A[p].s;
               sol += new_pos(p, A[p].id);
            }
    }
    
	printf ("%d\n", sol);
 
	return 0;
}