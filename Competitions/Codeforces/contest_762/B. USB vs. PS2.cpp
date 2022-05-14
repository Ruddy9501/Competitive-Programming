/*
2017-01-25 18:32:51
https://codeforces.com/contest/762/problem/B
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int a, b, n, can, c;
char C[100];
ll sol, co;
vector <ll> A, B;
 
 
int main(){
 
    scanf ("%d %d %d", &a, &b, &c);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%lld %s", &co, C);
         if (C[0] == 'U')
             A.push_back(co);
          else
            B.push_back(co);
    }
 
    sort (A.begin(), A.end());
    sort (B.begin(), B.end());
 
    for (int i = 1;  i <= a; i++){
         if (i > A.size())break;
         sol += A[i-1];
         can++;
    }
 
    for (int i = 1;  i <= b; i++){
         if (i > B.size())break;
         can++;
         sol += B[i-1];
    }
 
    while ( a < A.size() || b < B.size()){
           if (c == 0)break;
           can++;
           if (A.size() > a && B.size() > b){
               if (A[a] < B[b]){
                   sol += A[a];
                   c--, a++;
               }
                else{
                   sol += B[b];
                   c--, b++;
                }
                continue;
           }
 
           if (A.size() > a){
               sol += A[a];
               c--, a++;
               continue;
           }
          
           if (B.size() > b){
              sol += B[b];
              c--, b++;
           }
 
    }
 
    printf ("%d %lld\n", can, sol);
 
    return 0;
}