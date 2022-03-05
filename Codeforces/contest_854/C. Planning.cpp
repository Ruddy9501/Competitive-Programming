/*
2017-09-06 16:39:18
https://codeforces.com/contest/854/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e6 + 5;
int n, a, k, S[RAN], pos = 1, c;
long long sol;
 
struct par{
       int id, cos;
       par(int a = 0, int b = 0){
       	   id = b;
       	   cos = a;
       }
       bool operator <(const par &R)const{
       	    return cos < R.cos; 
       } 
 
};
 
priority_queue <par> Q;
 
int main(){
 
    scanf ("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d", &a);
    	 Q.push(par(a, i));
    	 if (i > k){
    	 	 par b = Q.top();
    	 	 Q.pop();
             sol += 1ll *(pos-b.id) * b.cos; 
             S[b.id] = pos;
    	 }
    	 pos++;
    }
 
    while (!Q.empty()){
    	 	 par b = Q.top();
    	 	 Q.pop();
             sol += 1ll *(pos - b.id) * b.cos; 
             S[b.id] = pos;
             pos++;
    }
 
    printf ("%lld\n", sol);
    for (int i = 1; i <= n; i++){
    	 if (i == 1) printf ("%d", S[i]);
    	  else printf (" %d", S[i]);
    }
    printf ("\n");
 
    return 0;  
}