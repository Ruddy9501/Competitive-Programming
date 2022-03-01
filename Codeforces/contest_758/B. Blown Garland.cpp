/*
2017-01-19 18:24:45
https://codeforces.com/contest/758/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
char A[10000], V[10];
int r, b, y, g;
 
int main(){
 
    scanf ("%s", A);
    int la = strlen (A);
 
    for (int i = 0; i < la; i++){
         if (A[i] != '!')
             V[i%4] = A[i];
    }
 
    for (int i = 0; i < la; i++){
         if (A[i] == '!'){
             if (V[i%4] == 'R')r++;
             if (V[i%4] == 'B')b++;
             if (V[i%4] == 'Y')y++;
             if (V[i%4] == 'G')g++;
         }
    }
 
    printf ("%d %d %d %d\n", r, b, y, g);
 
    return 0;
}