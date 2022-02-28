#include <bits/stdc++.h>

using namespace std;
int a, l, h;
int main(){

    scanf ("%d%d%d", &a, &l, &h);
    for (int i = 0; i <= a; i++){
          
    	 for (int j = 0; i+j <= a; j++){
              
              if (2*i + 4*j > l) break;
              if (2*j > h) break;
    	 	  for (int k = 0; i+j+k <= a; k++){
                   
                   if (2*i + 4*j+4*k > l) break;
                   if (2*j+k > h) break;

    	 	  	   if (i+j+k == a && 2*i + 4*j + 4*k == l && 2*j+k == h){
    	 	  	   	   printf ("%d\n", k);
    	 	  	   	   return 0;
    	 	  	   }
    	 	  }
    	 }
    }

	return 0;
}