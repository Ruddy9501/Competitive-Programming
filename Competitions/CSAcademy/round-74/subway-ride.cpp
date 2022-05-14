#include <bits/stdc++.h>

using namespace std;
int a, n, sol, c[1000];
int main(){

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 for (int j = 1; j <= n; j++){
    	 	  scanf ("%d", &a);
    	 	  int k = j-i;
    	 	  if (j < i) k = n-i + j;
    	 	  int pos = i;
    	 	  while (k--){
    	 	  	     c[pos]+=a;
    	 	  	     if (pos == n) pos = 1;
    	 	  	      else pos++;
    	 	  }
    	 }
    }

    for (int i = 1; i <= n; i++) sol = max (sol, c[i]);

    printf ("%d\n", sol); 	

	return 0;
}