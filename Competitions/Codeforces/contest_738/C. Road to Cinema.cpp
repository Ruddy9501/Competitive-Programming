/*
2016-11-22 00:07:29
https://codeforces.com/contest/738/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2*1e5+5;
int n, k, s, t;
int G[RAN];
 
struct par{
       int cos, cap;
       bool operator<(const par &R)const{
       	    return cap < R.cap;
       }
}A[RAN];
 
bool is_ver(int p){
     //cout << "---------\n"; 
	 if (s > t) return false;
     
     int tt = 0;
	 for (int i = 1; i <= k+1; i++){
          int dis = G[i]-G[i-1];
//          cout << dis << "-------\n";
          if (dis > A[p].cap) return false;
           else{
           //	cout << dis << " " << A[p].cap - dis << "\n";
           	if (dis - (A[p].cap - dis) <= 0)
           	    tt += dis;
             else tt += (2*(dis-(A[p].cap - dis)))  + A[p].cap-dis;  
             //cout << tt << "\n"; 
           }
	 }
     
//cout << A[p].cos << " " << A[p].cap << " " << tt << "\n";
 
	 if (tt <= t) return true;
 
	 return false;
} 
 
int main(){
    
    //cin >> n >> k >> s >> t;
    
    scanf ("%d%d%d%d",&n,&k,&s,&t); 
    for (int i = 1; i <= n; i++){
    	 //cin >> A[i].cos >> A[i].cap;
    	scanf ("%d%d", &A[i].cos, &A[i].cap);
    }
 
    for (int i = 1; i <= k; i++)
    	 scanf ("%d", &G[i]);//cin >> G[i];
 
    sort (G+1,G+k+1); 	 G[k+1] = s;
    sort (A+1,A+n+1);
    //for (int i = 1; i <= n+1; i++) cout << G[i] << " ";
 
    int ini = 1, fin = n, sol = -1; 	
    while (ini <= fin){
    	   //cout << ini << " " << fin<<"----\n";
    	   int piv = (ini+fin)/2;
    	   if (is_ver(piv))
    	   	   sol = piv, fin = piv-1;
    	   	 else
               ini = piv+1;
    }
 
    if (sol == -1) {
    	cout << "-1\n";
    	return 0; 
    }
    
    int s = A[sol].cos;
    for (int i = sol; i <= n; i++)
    	 s = min(A[i].cos, s);
 
    cout << s << "\n";
 
	return 0;
}