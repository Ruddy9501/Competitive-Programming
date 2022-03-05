/*
2017-03-30 02:20:00
https://codeforces.com/contest/789/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e6 + 5;
 
int n, m , a, b;
long long sol, C[RAN];
vector <int> v[RAN];
bool M1[RAN], M[RAN];
int can = 1;
 
void dfs(int nod){
	 M[nod] = true;
	//cout << nod << " " << can << "\n";
	 for (int i = 0; i < (int)v[nod].size(); i++){
	 	  int newn = v[nod][i];
	 	  if (M[newn]) continue;
	 	  M[newn] = true;
	 	  can++;
	 	  dfs (newn);
	 }
}
 
 
int main(){
    
    scanf("%d%d", &n ,&m); long long r = 0;
    for (int i = 1; i <= m; i++){
    	 scanf ("%d%d", &a, &b);
    	 
    	 if (a==b) 
     	 	 C[a]++, r++;
   	  	 else{
   	  	 	v[a].push_back(b);
   	        v[b].push_back(a);
         }
    }
 
    M[1] = true;
    for (int i = 1; i <= n; i++)
    	 if (v[i].size() > 0){
    	 	 dfs (i); 
    	 	// cout << i << " " << can << "\n";
    	 	 break;
    	 }
 
    for (int i = 1; i <= n; i++)
    	 if ((int)v[i].size() == 0 && !C[i]) can++;
 
    if (can != n){ //cout << can <<"\n";
    	cout << "0\n";
    	return 0; 
    }
    
    for (int i  = 1; i <= n; i++){
    	 long long x = (int)v[i].size();
    //	 cout << i << " " << x<<"\n";
    	 sol += (x)*(x-1ll)/2;
    	 if (C[i] && x > 0) sol += (m-1);
    }
        
	printf("%lld\n", sol - r*(r-1)/2);
 
	return 0;
}