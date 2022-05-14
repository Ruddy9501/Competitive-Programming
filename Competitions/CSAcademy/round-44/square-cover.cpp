#include <bits/stdc++.h>

using namespace std;
const int RAN = 1e5 + 5;
int n, m, a, x[RAN], y[RAN], X[RAN], Y[RAN], C[RAN];

int main(){
    
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
    	 for (int j = 1; j <= m; j++){
    	 	  scanf ("%d", &a);
    	 	  C[a]++;
    	 	  if (x[a] == 0) x[a] = i;
    	 	  if (y[a] == 0) y[a] = j;

    	 	  X[a] = max (X[a], i);
    	 	  Y[a] = max (Y[a], j);
    	 }
    }


    for (int i = 0; i <= 1e5; i++){
         int can = C[i]; 
         int r = sqrt (can);
         if (can == 0) continue;

         if (r * r != can || X[i] - x[i] +1 != r || Y[i]-y[i]+1 != r){
         	 printf ("0\n");
         	 return 0;
         }
    }

    printf ("1\n");



	return 0;
}