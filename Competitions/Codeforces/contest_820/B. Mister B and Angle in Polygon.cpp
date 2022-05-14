/*
2017-06-27 17:58:18
https://codeforces.com/contest/820/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
 
    int n, c;
    double a;
    scanf ("%d %lf", &n, &a);
    double ang = 0, sum = 360.0/n/2, sol = 360;
    for (int i = 1; i <= n-2; i++){
         ang += sum;
         if (sol > fabs(ang-a)){
             sol = fabs(ang-a);
             c = i+2;
         }
    }
 
    printf ("%d 1 2\n", c);
 
    return 0;
}