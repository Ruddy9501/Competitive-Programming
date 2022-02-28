#include <bits/stdc++.h>

using namespace std;

int n, a[1000], s[1000];

int main(){

    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
    	 scanf ("%d", &a[i]);
    }
    
    int p = 1, pos = 0;
    while (p < n){ 
           if (a[pos] < a[p]) pos = p; 
           	s[pos]++;
           	p++;
    }
    
    
    printf ("%d", s[0]);
    for (int i = 1; i < n; i++){
    	 printf (" %d", s[i]);
    } printf ("\n");


	return 0;
}