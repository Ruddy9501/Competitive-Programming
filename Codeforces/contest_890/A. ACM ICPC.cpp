/*
2017-11-28 18:21:55
https://codeforces.com/contest/890/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int tot, a[10];
 
int main(){
	
	for (int i = 0; i < 6; i++){
	     scanf ("%d", &a[i]);
	     tot += a[i];
	}
	
	bool ok = false;
	for (int i = 0; i < 6; i++){
	     for (int j = i+1; j < 6; j++){
			  for (int k = j+1; k < 6; k++){
			       if (2*(a[i]+a[j]+a[k]) == tot) ok = true;
			  }
		  }
	}
	
	if (ok) printf ("YES\n");
	else printf ("NO\n");
	
    return 0;
}