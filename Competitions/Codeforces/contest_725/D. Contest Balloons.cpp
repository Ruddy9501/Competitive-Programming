/*
2016-10-22 19:56:47
https://codeforces.com/contest/725/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
priority_queue <ll, vector<ll>, greater<ll> >Q;
int n, sol;
ll k;
int p;
struct par{
       ll v, p;
       bool operator<(const par &R)const{
            return v > R.v;
       }
}A[300005];
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%I64d %I64d", &A[i].v, &A[i].p);
    }
 
    sort (A+2,A+n+1);
 
    for ( p = 2; A[p].v > A[1].v && p <= n; p++){
         Q.push(A[p].p-A[p].v+1ll);
    }
 
    sol = Q.size()+1;
    k = A[1].v;
    while (k > 0 && !Q.empty()){
           ll  pp = Q.top();
           Q.pop();
           if (pp > k) break;
 
           if (k >= pp)
               k-=pp;
 
           while (A[p].v > k && p <= n){
                  Q.push(A[p].p-A[p].v+1ll);
                  p++;
           }
 
           if (sol > (ll)Q.size()+1ll)
               sol  = (ll)Q.size()+1ll;
    }
 
    printf ("%d\n", sol);
 
    return 0;
}