#include <bits/stdc++.h>

using namespace std;

int n, sol, a[200005];

int main(){

    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    	 scanf ("%d", &a[i]);
    
    int s1 = 1;
    for (int i = 0; i < n; i++){
         int ii = i;
         
         while (ii < n-1 && a[ii] <= a[ii+1]) ii++;
         //printf ("%d %d\n", i, ii-i+1);
         s1 = max (s1, ii-i+1);
         i = ii;

        // printf ("%d %d\n", i, ii-i+1);
    }	
    
    int s2 = 1;
    for (int i = 0; i < n; i++){
         int ii = i;

         while (ii < n-1 && a[ii] >= a[ii+1]) ii++;
         //printf ("%d %d\n", i, ii-i+1);
         s2 = max (s2, ii-i+1);
         i = ii;
         
    }	

    printf ("%d\n", max(s1, s2));


 	return 0;
}