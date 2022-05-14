#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
int n, b, a[MAX], x[MAX];
long long sol;

bool orden (){ 
     

     for (int i = 1; i < n; i++)
     	  if (a[i] < a[i-1]) return false;
     return true;
}

int main(){
	
    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
    	 scanf ("%d", &a[i]);
    	 x[i] = a[i];  
    }
    
    
    long long can;
    if (orden ()){
    	can = 1;
    	for (int i = 1; i < n; i++){
    		 if (a[i] != a[i-1]){
    		     sol += can*(can+1ll)/2ll;
    		     can = 1;
    		 }
    		  else can++;
    	}


    	printf ("%lld\n", sol + can*(can+1ll)/2ll);
    	printf ("1 1\n");
    	return 0; 
    }

    sort (x, x+n); 
    for (int i = 0; i < n; i++){
         if (a[i] != x[i]){
         	 int p = upper_bound (x, x+n, a[i]) - x;
         	 reverse (&a[i], &a[p]);
         	 
         	 if (orden()){
         	 	 printf ("1\n");
    	         printf ("%d %d\n", i+1, p);
    	         return 0;
         	 }

         	 printf ("0\n");
         	 break;
         } 
    }

	return 0;
}