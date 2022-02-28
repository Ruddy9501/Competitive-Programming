/*
2018-03-17
*/
#include <bits/stdc++.h>
 
using namespace std;
int a, b;
int main(){
 
    scanf ("%d %d", &a, &b);
    a = 6 - max (a, b) + 1;
    int g = __gcd (a, 6);
 
    printf ("%d/%d\n",a/g, 6/g);
 
	return 0;
}