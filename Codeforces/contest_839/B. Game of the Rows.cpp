/*
2017-08-14 18:03:55
https://codeforces.com/contest/839/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
priority_queue <int> Q;
int n, k, uno, dos, a, cua;
 
int main(){
 
    scanf ("%d%d", &n, &k);
    for (int i = 0; i < k; i++){
         scanf ("%d", &a);
         Q.push(a);
    }
 
    cua = n; dos = 2*n;
 
    while (!Q.empty() && (cua > 0 || dos > 0)){
           a = Q.top();
           Q.pop();
 
           if (a >= 3 && cua > 0){
               cua--;
               a -= 4;
               if (a > 0) Q.push(a);
               continue;
           }
 
           if (a >= 3 && dos > 0){
               dos--;
               a -= 2;
               Q.push(a);
               continue;
           }
 
           if (dos > 0){
               a -= 2;
               dos--;
               if (a > 0) Q.push(a);
               continue;
           }
 
           if (cua > 0){
               cua--;
               if (a == 1) dos++;
               if (a == 2) uno++;
               continue;
           }
    }
 
    while (!Q.empty() && uno){
           int a = Q.top();
           Q.pop();
           uno--;
           a--;
           if (a>0) Q.push(a);
    }
 
    if (Q.empty()) {
        printf ("YES\n");
        return 0;
    }
 
    printf ("NO\n");
 
    return 0;
}