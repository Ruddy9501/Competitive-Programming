/*
2017-11-20 17:16:01
https://codeforces.com/contest/892/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef pair <int, int> par;
 
const int MAX = 5e5 + 5;
int n, m, q, x, y, z, ran[MAX], id[MAX];
bool s[MAX], mar[MAX];
 
vector <int> g[MAX];
vector <par> v[MAX];
 
struct tre{
       int x, y, z;
       bool operator <(const tre &r)const{
	        return z < r.z;
	   }   
}c[MAX], a[MAX];
 
int find_set (int x){
    if (id[x] == x) return x;
    return id[x] = find_set (id[x]);
}
 
bool ok;
 
void dfs (int u, int pt = 0){
	 mar[u] = true;
     for (int v : g[u]){
          if (pt == v) continue;
          
          if (mar[v]) 
              ok = false;
           else 
              dfs (v, u);
	 } 
	 
	 //mar[u] = false;
}
 
void joind_set (int x, int y){
     if (ran[x] < ran[y])
         swap (x, y);
         
     ran[x] += ran[y];
     id[y] = x;    
}
 
int main(){
    
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
	     scanf ("%d%d%d", &x, &y, &z);
	     c[i] = (tre){x, y, z}; 
	     a[i] = (tre){x, y, z};
	}
	
	scanf ("%d", &q);
    for (int i = 1; i <= q; i++){
		 int d;
	     scanf ("%d", &d);
	     while (d--){
		        int p;scanf ("%d", &p);
		        z = a[p].z;
		        v[z].push_back (par(p, i));  	          
		 } 
	}
	
	for (int i = 1; i <= n; i++)
         id[i] = i, ran[i] = 1;
    
    fill (s, s+q+1, true);     
    sort (c+1, c+m+1);
    int p = 0;
    for (int i = 1; i <= m; i++){
	     int xx = find_set (c[i].x); 
	     int yy = find_set (c[i].y); 
	     z = c[i].z; 
	    //printf ("%d \n------------\n", c[i].z);    
	     while (p <= z){
			    
		        if (v[p].empty()){
				    p++;
				    continue;
				}
		       // printf ("+++ %d\n", (int)v[p].size());
		        int j = 0;
		        for ( ; j < (int)v[p].size(); j++){
				     
				     int jj = j;
				     vector <int> pos;
				     for ( ; jj < (int)v[p].size() && v[p][j].second == v[p][jj].second; jj++) 
				          pos.push_back (v[p][jj].first);
				     
				     j = jj - 1;
				        
				     for (int k = 0; k < (int)pos.size(); k++){
						  int b = pos[k];
						  x = find_set (a[b].x);
						  y = find_set (a[b].y);
						 // printf ("x: %d y: %d %d %d\n", x, y, a[b].x, a[b].y);
				          g[x].push_back (y);
				          g[y].push_back (x);
					 }
					   
					// printf ("j: %d\n", j);
					 for (int k = 0; k < (int)pos.size(); k++){
					      x = find_set (a[pos[k]].x);
					      
					      if (mar[x]) continue;
					      ok = true;
					      dfs (x);
					     // printf ("%d %d %d\n", x, v[p][j].second, ok);
					      s[v[p][j].second] &= ok;					      
					 }
					 
					 for (int k = 0; k < (int)pos.size(); k++){
						  int b = pos[k];
						  x = find_set (a[b].x);
						  y = find_set (a[b].y);
				          g[x].clear ();
				          g[y].clear ();
				          mar[x] = mar[y] = false;
					 }
				}
				
				p++;
		 }
		 
		 if (xx != yy) joind_set (xx, yy);
		 
	}
    
    for (int i = 1; i <= q; i++)
         if (s[i]) printf ("YES\n");
          else printf ("NO\n");
          
    return 0;
}