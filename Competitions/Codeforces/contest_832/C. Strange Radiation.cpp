/*
2017-08-03 17:46:39
https://codeforces.com/contest/832/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5 + 5;
const int MAX = 1e6;
 
 
struct tres{
       int x, v, d; 
}A[RAN];
 
int n, s, x, v, d, cx[MAX+5], cy[MAX+5];
 
bool ok(double t){
     
     fill (cx, cx+MAX+1, 0); 
     fill (cy, cy+MAX+1, 0); 
 
     for (int i = 1; i <= n; i++){
     	  if (A[i].d == 1){
     	  	  if (1.0 * A[i].x <= t * A[i].v) cx[0]++;
     	  	  else{
     	  	  	  if (A[i].x <= t * (A[i].v+s)){
     	  	  	  	  long long a = 1.0 * (A[i].x - t * (A[i].v + s)) * (s - A[i].v);
					  a = -a / s;
					  cx[A[i].x]++;
					  cx[min(1ll*MAX+1, A[i].x + a + 1)]--;
     	  	  	  }
     	  	  } 
     	  }
 
     	  else{
     	  	  long long x = 1000000 - A[i].x;
     	      if (1.0 * x <= t * A[i].v) cy[0]++;
     	  	   else{
     	  	       if (x <= t * (A[i].v+s)){
     	  	     	   long long a = 1.0 * (x - t * (A[i].v + s)) * (s - A[i].v);
				 	   a = -a / s;
					   cy[max(0LL, A[i].x - a)]++;
					   cy[A[i].x + 1]--;
     	  	  	  }
     	  	  } 
     	  }
     }
 
    int a = 0, b = 0;
	for(int i = 0; i <= MAX; i++){
		a += cx[i];
		b += cy[i];
 
		if(a > 0 && b > 0)return true;
	}
 
	return false; 
}
 
int main(){
	
    scanf ("%d %d", &n, &s);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d %d %d", &x, &v, &d);
          A[i] = tres{x, v, d}; 
    }
 
    double ini = 0.0, fin = 1e6;
    for (int i = 0; i < 50; i++){
    	 double piv = (ini+fin)/2.0;
    	 if (ok(piv))
    	 	 fin = piv;
    	  else 
    	     ini = piv; 	
    }
 
    printf ("%.7lf\n", (ini+fin)/2.0);
 
	return 0;
}