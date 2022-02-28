/*
2015-03-26 19:54:07
https://codeforces.com/contest/525/problem/B
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
 
int n, la, ini, fin, a, S[1000000];
char A[1000000];
 
int main(){
 
    scanf ("%s", A+1);
    la = strlen (A+1);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a);
 
         ini = a;
         fin = la-a+1;
         if (la%2==1 && ini == fin) continue;
         S[ini]++;
         S[fin+1]--;
    }
 
    for (int i = 1; i <= la; i++)
         S[i] += S[i-1];
 
    for (int i = 1; i <= (la+1)/2; i++){
         if (S[i] % 2 == 1) swap(A[i],A[la-i+1]);
    }
 
    for (int i = 1; i <= la; i++) printf ("%c", A[i]);
    printf ("\n");
 
    return 0;
}