/*
2017-09-05 17:33:06
https://codeforces.com/contest/851/problem/C
*/
#include <bits/stdc++.h>
 
 
using namespace std; 
const double Pi = acos(-1);
 
int n, S[1005], can;
struct punto{
       double x[7]; 
}A[1005];
 
double calc(int a, int b, int c){
	   double num = 0, m1 = 0, m2 = 0;
	   for (int i = 1; i < 6; i++){
            num += (A[a].x[i] - A[b].x[i]) * (A[a].x[i] - A[c].x[i]);
            m1 +=  (A[a].x[i] - A[b].x[i]) * (A[a].x[i] - A[b].x[i]); 
            m2 +=  (A[a].x[i] - A[c].x[i]) * (A[a].x[i] - A[c].x[i]);
	   }
 
	  
	   double den = sqrt(m1) * sqrt(m2);
 
	   return acos(num/den)*180.0/Pi;
}
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
    	 scanf ("%lf %lf %lf %lf %lf", &A[i].x[1], &A[i].x[2], &A[i].x[3], &A[i].x[4], &A[i].x[5]);
    
 
    if (n > 100) {
    	printf ("0\n");
    	return 0;
    }
 
    for (int i = 1; i <= n; i++){
    	 bool ok = true;
    	 for (int j = 1; j <= n; j++){
    	 	  for (int k = 1; k <= n; k++){
    	 	       if (i == j || i == k || j == k) continue;
    	 	      // printf ("%lf\n", calc(i, j, k));
    	 	       if (calc(i, j, k) < 90.0) ok = false;
    	 	  }
    	 }
 
    	 if (ok) S[++can] = i;
    	 //break;
    }
    
    printf ("%d\n", can); 
    for (int i = 1; i <= can; i++) printf ("%d\n", S[i]);
 
	return 0; 
}