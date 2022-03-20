/*
2017-11-28 01:23:12
https://codeforces.com/contest/893/problem/F
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int oo = INT_MAX;
const int MAX = 1e5 + 5;
int n, root, x, y, k, q, last, l[MAX], p[MAX], v[MAX], c[MAX], inv[MAX];
vector <int> g[MAX];
 
struct par{
       int v, id;
       bool operator <(const par &r)const{
	        if (v != r.v) return v < r.v;
	        return id < r.id; 
	   } 
};
 
struct node{
       vector <par> d;
       vector <int> s;
}st[4*MAX];
 
void dfs (int u, int pt = 0, int di = 0){
     l[u] = di;
     p[u] = ++k;
     inv[k] = u;
     
     //printf ("++++ %d %d %d\n", u, l[u], inv[k]);
     
     for (int v : g[u]){
		 
	      if (v == pt) continue;
	      
	      dfs (v, u, di+1);
	      c[u] += c[v];
	 }
     
     c[u]++;     
}
 
void built (int ini, int fin, int p){
     
     if (ini == fin){
	     st[p].d.push_back ((par){l[inv[ini]], inv[ini]});
	     st[p].s.push_back (v[inv[ini]]);
	     
	     /*printf ("%d %d\n", ini, fin);
	     printf ("%d\n-------------\n", st[p].s[0]);*/
	     
	     return ; 
	 }
	 
	 int piv = (ini+fin)/2;
	 built (ini, piv, p*2);
	 built (piv+1, fin, p*2+1);
     
     int l1 = (int)st[p*2].d.size();
     int l2 = (int)st[p*2+1].d.size();
     st[p].d.resize (l1 + l2);     
     st[p].s.resize (l1 + l2);     
     
     merge (st[p*2].d.begin(), st[p*2].d.begin()+l1, st[p*2+1].d.begin(), st[p*2+1].d.begin()+l2, st[p].d.begin());
     
     st[p].s[0]  = v[st[p].d[0].id];
     for (int i = 1; i < l1+l2; i++)
          st[p].s[i] = min (st[p].s[i-1], v[st[p].d[i].id]);
     
     /*printf ("%d %d\n", ini, fin);
     for (int i = 0; i < l1+l2; i++) printf ("%d ", st[p].s[i]);
     printf ("\n-----------------\n"); */
}
 
int query (int ini, int fin, int p, int a, int b, int dis){
 
    if (ini > b || fin < a) return oo; 
 
    if (ini >= a && fin <= b){
	    int pos = upper_bound (st[p].d.begin(), st[p].d.end(), (par){dis, oo}) - st[p].d.begin();
	    if (pos == 0) return oo;
	    pos--;
	    
	    //printf ("+++++ %d %d %d\n", ini, fin, st[p].s[pos]);
	    
	    return st[p].s[pos];
	}
	
	int piv = (ini+fin) / 2;
	return min (query (ini, piv, p*2, a, b, dis), query (piv+1, fin, p*2+1, a, b, dis)); 
}
 
int main(){
    
    scanf ("%d%d", &n, &root);
    
    for (int i = 1; i <= n; i++)
         scanf ("%d", &v[i]);
    
    for (int i = 1; i < n; i++){
	     scanf ("%d%d", &x, &y);
	     g[x].push_back (y);
	     g[y].push_back (x);
	}
	
	dfs (root);
	built (1, n, 1);
	
	scanf ("%d", &q);
	while (q--){
	       scanf ("%d %d", &x, &y);
	      
	       x = (x + last) % n + 1;
	       y = (y + last) % n;
	       
	       int ini = p[x];
	       int fin = ini + c[x] - 1;
	       int dis = l[x] + y;
	       
	      // printf ("%d %d %d\n", ini, fin, dis);
	            
	       last = query (1, n, 1, ini, fin, dis);
	       printf ("%d\n", last);
	} 
 
    return 0;
}