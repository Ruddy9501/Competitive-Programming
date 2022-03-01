/*
2017-01-16 21:52:59
https://codeforces.com/contest/749/problem/A
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int n, can;
int main(){
 
    scanf ("%d", &n);
 
    if (n % 2){
        printf ("%d\n", 1+(n-3)/2);
        printf ("3");
        n-=3;
        for ( ; n > 0; n -= 2) printf (" 2");
    }
    else{
        printf ("%d\n", n/2);
        printf ("2");
        n-=2;
        for ( ; n > 0; n -= 2) printf (" 2");
    }
    printf ("\n");
    return 0;
}