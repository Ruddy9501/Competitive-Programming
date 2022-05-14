#include <bits/stdc++.h>

using namespace std;

int n;
int A[1005];

int main(){
    
    scanf ("%d", &n);
    int sol = 0, ma = INT_MIN;
    for (int i = 0; i < n; i++){
    	 scanf ("%d", &A[i]);
    	 if (ma < A[i]) sol++;
    	 ma = max(A[i], ma);
  
    }

    printf ("%d\n", sol);

	return 0;
}