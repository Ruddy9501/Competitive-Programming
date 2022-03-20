/*
2017-10-30 18:40:27
https://codeforces.com/contest/879/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 5e5 + 5;
int n, a[MAX], d[MAX];
char c[MAX];
 
int calc (char car, int a, int b){
	if (car == '|') return a|b; 
	if (car == '^') return a^b;
	return a&b; 
}
 
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++)
    	 cin >> c[i] >> a[i];
    
    int x = 0, y = 0, z = 0, v = (1<<10) - 1;
    for (int i = 0; i < 10; i++){
    	 for (int j = 0; j <= 1; j++){
    	 	  int b = j * (1<<i);
    	 	  for (int k = 1; k <= n; k++)
    	 	  	   b = calc (c[k], b, a[k]);
    	 	  d[j] = b;	
    	 }
         bool d1 = d[0] & (1<<i);
         bool d2 = d[1] & (1<<i);
 
         if (d1 && d2) x |= 1<<i, y |= 1<<i;
         if (!d1 &&  d2) y |= 1<<i;
         if (d1 && !d2) z |= 1<<i, y |= 1<<i;
         if (!d1 && !d2	)
         	 v ^= 1<<i;
 
    }
    
    printf ("%d\n", 4);
    printf ("| %d\n", x);
    printf ("& %d\n", y);
    printf ("& %d\n", v);
    printf ("^ %d\n", z);
 
 
	return 0;
}