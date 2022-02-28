/*
2015-06-04 21:23:00
https://codeforces.com/contest/550/problem/A
*/
#include <map>
#include <set>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
char A[1000005];
int c1, c2, la;
bool M[1000005];
int main(){
 
    cin >> A;
    la = strlen (A);
    for (int i = 0; i < la; i++){
         if (A[i] == 'A' && A[i+1] == 'B'){
             for (int j = i+2; j<la;j++)
             if (A[j]=='B'&&A[j+1]=='A') {
                 printf("YES\n");
                return 0;
             }
             break;
         }
    }
 
     for (int i = 0; i < la; i++){
         if (A[i] == 'B' && A[i+1] == 'A'){
             for (int j = i+2; j<la;j++)
             if (A[j]=='A'&&A[j+1]=='B') {
                 printf("YES\n");
                return 0;
             }
             break;
         }
    }
 
    printf ("NO\n");
 
    return 0;
}