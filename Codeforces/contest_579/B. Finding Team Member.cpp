/*
2015-09-16 18:46:22
https://codeforces.com/contest/579/problem/B
*/
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n, a, b, c, S[1000000];
 
struct par{
       int a, b, cos;
       bool operator<(const par &R)const{
            return R.cos > cos;
       }
}A[1000000];
 
int main(){
 
    scanf ("%d", &n);
 
    for (int i = 2; i <= n*2; i++)
    for (int j = 1; j < i; j++){
              scanf ("%d", &A[++c].cos);
              A[c].a = i;
              A[c].b = j;
 
    }
 
    sort (A+1,A+c+1);
 
    while (c){
           a = A[c].a;
           b = A[c].b;
           if (S[a]==0&&S[b]==0){
               S[a] = b;
               S[b] = a;
           }
           c--;
    }
 
    for (int i = 1; i < n*2; i++) printf ("%d ", S[i]);
    printf ("%d\n", S[2*n]);
 
    return 0;
}