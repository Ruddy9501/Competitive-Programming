/*
2016-11-03 21:26:05
https://codeforces.com/contest/730/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, a, sol1, sol2, tot;
bool m[15000][105], m1[15000][105];
struct par{
	   int v, id;
	   bool operator <(const par &R)const{
	   	    return v < R.v;
	   }
}M[105], M1[105];
 
 
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++){
    	 cin >> a;
    	 M[i] = par{a, i};
    	 M1[i] = par{a, i};
    }
    bool mar = 1;
    while (1){
    	  sort (M+1, M+n+1);
    	  if (M[1].v == M[n].v) break;
    	  sol1++; tot = 0;
    	  for (int i = 2; i <= n; i++) tot += M[i].v;
    	  if (mar && n > 2){mar = 0;
    	      if (M[n].v   > 0) M[n].v--; 
    	      if (M[n-1].v > 0) M[n-1].v--; 
    	      if (M[n-2].v > 0) M[n-2].v--;
    	      m[sol1][M[n].id] = true;
    	      m[sol1][M[n-1].id] = true;
    	      m[sol1][M[n-2].id] = true;
    	  }
    	  else{
    	  	  if (M[n].v   > 0) M[n].v--; 
    	      if (M[n-1].v > 0) M[n-1].v--; 
    	      m[sol1][M[n].id] = true;
    	      m[sol1][M[n-1].id] = true;
    	  }	
    }
    
    while (1){
    	  sort (M1+1, M1+n+1);
    	  if (M1[1].v == M1[n].v) break;
    	  sol2++; 
    	  if (M1[n].v   > 0) M1[n].v--; 
    	  if (M1[n-1].v > 0) M1[n-1].v--; 
    	  m1[sol2][M1[n].id] = true;
    	  m1[sol2][M1[n-1].id] = true;	
    }
     
    if (M[1].v > M1[1].v){
	    cout << M[1].v << "\n";
	    cout << sol1 << "\n";
	    for (int i = 1; i <= sol1; i++){
	    	 for (int j = 1; j <= n; j++){
	    	 	 if (m[i][j]) cout << "1";
	    	 	  else cout << "0";
	    	 }
	    	 cout << "\n";
	    }
	}
	 else{
	 	cout << M1[1].v << "\n";
	    cout << sol2 << "\n";
	    for (int i = 1; i <= sol2; i++){
	    	 for (int j = 1; j <= n; j++){
	    	 	 if (m1[i][j]) cout << "1";
	    	 	  else cout << "0";
	    	 }
	    	 cout << "\n";
	    }
	 }
	return 0;
}