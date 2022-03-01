/*
2016-12-06 17:44:35
https://codeforces.com/contest/742/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
 
int main(){
 
    scanf ("%d", &n);
    if (n == 0){
        printf ("1\n");
        return 0;
    }
    int lg = log2(n);
    int sol = 1, mul = 8;
    for (int i = 0; i <= lg; i++){
         if (n & (1<<i)) sol  = (sol*mul)%10;
         mul *= mul;
         mul %= 10;
    }
 
    printf ("%d\n", sol);
 
    return 0;
}