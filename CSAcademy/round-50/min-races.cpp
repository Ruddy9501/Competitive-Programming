#include <bits/stdc++.h>

using namespace std;
const int RAN = 1e5 + 5;

int n, k, id, p, B[RAN], ini, fin, sol, pos;
struct par{
       int id, p;
       bool operator <(const par &R)const{
       	    return p < R.p;
       }
}A[RAN];

int main(){

    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
    	 scanf ("%d %d", &id, &p);
    	 A[i] = par{id, p};
    }
    
    sort (A, A+n);
    fill (B, B+n+1, -1);
    for (int i = 0; i < n; i++){
    	 ini = 1; fin = n;
    	 pos = n;
    	 while (ini <= fin){
    	 	    int piv = (ini+fin)/2;
    	 	    if (B[piv] < A[i].id)
    	 	    	fin = piv-1, pos = piv;
    	 	     else 
    	 	        ini = piv+1;  	 
    	 }
   
    	 B[pos] = A[i].id;
    	 sol = max(sol, pos);
    }
    
    printf ("%d\n", sol);  

	return 0;
}