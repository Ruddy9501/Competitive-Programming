#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e4 + 5;
int n, A[MAX];
long long sol, C[MAX];

int main(){

    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
         scanf ("%d", &A[i]);  
         C[A[i]]++; 
    }
     
    
  
    
   sol = 1ll*C[0]*(C[0]-1ll)*(C[0]-2ll)/6ll;
   for (int i = 1; i <= 5000; i++){
   	    sol += 1ll*C[0]*C[i]*(C[i]-1ll)/2ll;
   	    sol += 1ll*C[i]*(C[i]-1ll)*C[i+i]/2ll;
   	    for (int j = i+1; j+i <= 5000; j++)
   	    	 if (C[i] && C[j] && C[i+j])
   	    	 	 sol += C[i]*C[j]*C[i+j];
   }

    printf ("%lld\n", sol);

	return 0;
}