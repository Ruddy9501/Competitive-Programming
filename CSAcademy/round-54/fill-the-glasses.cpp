#include <bits/stdc++.h>

using namespace std;

int n, k, tot, a[10000];

int main(){

    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    	 scanf ("%d", &a[i]);
    
    sort (a,a+n);
    for (int i = 0; i < k; i++)
    	 tot += a[i];

    printf ("%d\n", tot/100+(tot%100 != 0));	

	return 0;
}