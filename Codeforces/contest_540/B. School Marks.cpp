/*
2015-04-30 21:09:53
https://codeforces.com/contest/540/problem/B
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n, k, p, S, M, men, i, may, con, P, tot, s[100000], A[100000];
 
int main(){
 
    scanf ("%d%d%d%d%d",&n,&k,&p,&S,&M);
 
    for (int i = 1; i <= k; i++){
         scanf ("%d", &A[i]);
         S -= A[i];
    }
 
    sort (A+1,A+k+1);
 
    while (A[k/2+1] < M && k < n && S >= 0 && p >= M){
           A[++k] = M;
           s[++con] = M;
           S -= M;
          // sort (A+1,A+k+1);
    }
 
    while (A[k/2] >= M && k < n && S >= 0 && p >= M){
           A[++k] = 1;
           S -= 1;
           s[++con] = 1;
           sort (A+1,A+k+1);
    }
 
    if (k % 2 == 0){
        A[++k] = M;
        s[++con] = M;
        S -= M;
    }
 
    while (k < n && S >= 0){
           s[++con] = 1;
           A[++k] = 1;
           if (p >= M) s[++con] = M, A[++k] = M;
           S -= M;
           S -= 1;
    }
 
    sort (A+1,A+k+1);
 
    if (S < 0 || k > n || A[k/2+1] < M){
        printf ("-1\n");
    }
    else{
        printf ("%d", s[1]);
        for (int i = 2; i <= con; i++) printf (" %d", s[i]);
        printf ("\n");
    }
    return 0;
}