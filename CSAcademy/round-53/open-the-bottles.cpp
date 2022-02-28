#include <bits/stdc++.h>

using namespace std;

int A[4][4];


int main(){
    
    int sol = 0;
    for (int i = 0; i < 3; i++){
    	 int mi = INT_MAX;
    	 for (int j = 0; j < 3; j++){
    	 	  scanf ("%d", &A[i][j]);
    	 	  mi = min(mi, A[i][j]);
    	 }
        sol += mi;
    }
    
    printf ("%d\n", sol);

	return 0;
}