/*
2016-10-22 18:09:51
https://codeforces.com/contest/725/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, sol;
char A[1000000];
int main(){
 
    scanf ("%d", &n);
    scanf ("%s", A);
 
    for (int i = 0; i < n; i++){
         if (A[i] == '<') sol++;
          else break;
    }
 
    for (int i =n-1; i >= 0; i--){
         if (A[i] == '>') sol++;
          else break;
    }
 
    printf ("%d\n", sol);
 
    return 0;
}