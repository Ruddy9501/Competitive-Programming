/*
2015-04-30 19:37:17
https://codeforces.com/contest/540/problem/A
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int n, a, b;
long long sol;
char A[10000], B[10000];
 
int main(){
 
    scanf ("%d", &n);
    scanf ("%s", A);
    scanf ("%s", B);
 
    for (int i = 0; i < n; i++){
         a = A[i]-'0';
         b = B[i]-'0';
         if (a > b) swap (a, b);
         sol += min (abs(b-a),abs(10+a-b));
    }
 
    printf ("%I64d\n", sol);
    return 0;
}