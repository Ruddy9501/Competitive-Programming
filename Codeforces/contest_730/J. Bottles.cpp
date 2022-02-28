/*
2016-11-03 20:17:33
https://codeforces.com/contest/730/problem/J
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, p, S1[1000000], S2[1000000], s1, s2, t, T;
bool M[1000000];
struct par{
       int v, t;
       bool operator <(const par &R)const{
       	    if (t != R.t)return t > R.t;
       	    return v > R.v;
       }
}A[100000];
 
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++){
    	 cin >> A[i].v;
    	 t += A[i].v;
    }
    
    for (int i = 1; i <= n; i++){
    	 cin >> A[i].t;
    	 T += A[i].t;
    }
    
    M[0] = true;
    
    fill (S1+1, S1+T+1, 1<<30);
 //   fill (S2+1, S2+T+1, 1<<30);
 
    for (int i = 1; i <= n; i++){
    	 for (int j = T-A[i].t; j >= 0; j--){
    	 	  if (M[j]){
    	 	  	  M[j+A[i].t] = true;
    	 	  	  if (S1[j+A[i].t] > S1[j]+1) {
    	 	  	  	  S1[j+A[i].t] = S1[j]+1;
    	 	  	  	  S2[j+A[i].t] = S2[j] + A[i].v;
    	 	  	  }
    	 	  	  if (S1[j+A[i].t] == S1[j]+1) 
    	 	  	  	  S2[j+A[i].t] = max (S2[j+A[i].t], S2[j] + A[i].v);	
    	 	  }
    	 }
    }
 
    //cout << t << " "<<S2[7]<<" " << S1[7] <<"\n";
    
    s1 = 1<<30;
    for (int i = t; i <= T; i++){
    	 if (!M[i]) continue;
    	 if (s1 > S1[i]){
    	 	 s1 = S1[i];
    	 	 s2 = S2[i];
    	 }
    	 if (s1 == S1[i])
    	     s2 = max (s2, S2[i]); 	
    } 
    
    cout << s1 << " " << t-s2 << "\n";
 
	return 0;
}