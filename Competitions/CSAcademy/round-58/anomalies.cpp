#include <bits/stdc++.h>

using namespace std;

int n, k, sol, a[10000];

int main(){
	
	scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);	
	
	for (int i = 0; i < n; i++){
	     bool ok = true;
	     for (int j = 0; j < n; j++){
		     if (i == j) continue;
		     if (abs(a[i]-a[j]) <= k) ok = false;
		 }
		 sol += ok;
	}
	
	printf ("%d\n", sol);
	
	
    return 0;	
}	
 
