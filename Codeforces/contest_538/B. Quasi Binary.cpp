/*
2015-04-26 19:24:17
https://codeforces.com/contest/538/problem/B
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int la, m, mul, S[100];
char A[100];
int main(){
 
    scanf ("%s", &A);
    la = strlen (A);
 
    mul = 1;
    for (int i = la-1; i >= 0; i--){
         for (int j = 1; j <= A[i]-'0'; j++) S[j] += mul;
         mul *= 10;
         m = max (m, A[i]-'0');
    }
 
    sort (S+1,S+m+1);
 
    printf ("%d\n%d", m, S[1]);
    for (int i = 2; i <= m; i++)
         printf (" %d", S[i]);
    printf ("\n");
 
    return 0;
}