/*
2017-04-03 02:21:20
https://codeforces.com/contest/787/problem/D
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll oo = 1ll << 60;
const int RAN = 1e6 + 5;
typedef pair<int, ll> par;
 
int n, m, I, t, a, b, l, r, nod, newn;
ll C[RAN*10], c, cost, newc;
vector <par> v[RAN*10];
 
void build2 (int ini, int fin, int p){
     
     if (ini == fin){
     	 v[n+p].push_back (par(ini, 0));
     	 return ;
     }
 
     v[p+n].push_back (par(n+p*2, 0));
     v[p+n].push_back (par(n+p*2+1, 0));
    
	 int piv = (ini + fin)/2;
     build2 (ini, piv, p*2);
     build2 (piv+1, fin, p*2+1);
}
 
 
void build3 (int ini, int fin, int p){
     
     if (ini == fin){
     	 v[ini].push_back (par(4*RAN+n+p, 0));
     	 return ;
     }
 
     v[4*RAN+n+p*2].push_back (par(4*RAN+n+p, 0));
     v[4*RAN+n+p*2+1].push_back (par(4*RAN+n+p, 0));
 
	 int piv = (ini + fin)/2;
     build3 (ini, piv, p*2);
     build3 (piv+1, fin, p*2+1);
}
 
void update2 (int ini, int fin, int p, int a, int b, int nod, ll cos){
     
     if (ini > b || fin < a) return ;
 
     if (ini >= a && fin <= b){
     	 v[nod].push_back (par(p+n, cos));
     	 return ;
     }
 
     int piv = (ini + fin)/2;
     update2 (ini, piv, p*2, a, b, nod, cos);
     update2 (piv+1, fin, p*2+1, a, b, nod, cos);
}
 
void update3 (int ini, int fin, int p, int a, int b, int nod, ll cos){
     
	 if (ini > b || fin < a) return ;
 
	 if (ini >= a && fin <= b){
	 	 v[4*RAN+n+p].push_back (par(nod, cos));
	     return ;
	 } 
 
	 int piv = (ini + fin)/2;
     update3 (ini, piv, p*2, a, b, nod, cos);
     update3 (piv+1, fin, p*2+1, a, b, nod, cos);
}
 
struct par1{
       ll cos;
       int nod;
 
       par1 (ll cos, int nod) : cos(cos), nod(nod) {}
 
       bool operator <(const par1 &R) const{
       	    return cos > R.cos;
       }
};
 
priority_queue <par1> Q;
 
int main(){
 
    scanf ("%d %d %d", &n, &m, &I);
    build2 (1, n, 1);
    build3 (1, n, 1);
    for (int i = 0; i < m; i++){
    	 scanf ("%d", &t);
 
    	 if (t == 1){
    	 	 scanf ("%d %d %lld", &a, &b, &c);
    	 	 v[a].push_back(par(b, c));
    	 }
 
    	 if (t == 2){
    	 	 scanf ("%d %d %d %lld", &a, &l, &r, &c);
    	 	 update2 (1, n, 1, l, r, a, c);
    	 }
 
    	 if (t == 3){
             scanf ("%d %d %d %lld", &a, &l, &r, &c);
             update3 (1, n, 1, l, r, a, c);
    	 }
    }
 
    fill (C, C+5*RAN, oo); 
    C[I] = 0; 
    Q.push(par1(0, I)); 
    while (!Q.empty()){
    	   nod = Q.top().nod;
    	   cost = Q.top().cos;
    	   Q.pop();
    	   for (int i = 0; i < (int)v[nod].size(); i++){
    	   	    newn = v[nod][i].first;
    	   	    newc = v[nod][i].second + cost;
    	   	    if (newc < C[newn]){
                	C[newn] = newc;
                	Q.push(par1(newc, newn));
                }
    	   }
    }
    
    if (C[1] != oo)
    	printf ("%lld", C[1]);
     else 
        printf ("-1");
    
    for (int i = 2; i <= n; i++)
    	  if (C[i] != oo) 
    	  	  printf (" %lld", C[i]);
    	   else 
    	      printf (" -1");	
    
    printf ("\n");
 
	return 0;
}