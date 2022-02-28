/*
2017-10-13 18:30:50
https://codeforces.com/contest/510/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef long long int64;
 
const int MAX2 =  2e2 + 5;
const int MAX1 =  1e5 + 5;
const int F = MAX2 + 1;
const int S = MAX2 + 2;
 
 
 
int A[MAX2];
bool P[MAX1];
vector <int> par, imp;
 
namespace Dinic{
       
          typedef int T;
 
          struct edge{
                 int from, to;
                 T f;
          };
 
          const int MAX = 1e3 + 10;
          const T INF = INT_MAX;
 
          int n, s, t, can, pt[MAX], d[MAX], S[MAX][MAX];
          bool m[MAX][MAX], m1[MAX];
          vector <edge> e;
          vector <int> g[MAX], v[MAX], ss[MAX];
          queue <int> q;
 
          void init (int n_, int s_, int t_){
          	   n = n_, s = s_, t = t_;
 
          	   for (int i = 1; i <= n; i++)
          	   	    g[i].clear();
          	   	e.clear ();
          }
 
          void addEdge (int from, int to, T c){
 
              // printf ("from: %d to: %d c: %d\n", from, to, c);
 
          	   edge ed; m[from][to] = true;
          	   ed.from = from, ed.to = to, ed.f = c;
          	   e.push_back (ed);
          	   g[from].push_back ((int) e.size() - 1);
 
          	   ed.from = to, ed.to = from, ed.f = 0;
          	   e.push_back (ed);
          	   g[to].push_back ((int) e.size() - 1); 
          }
 
          bool bfs (){
          	   for (int i = 1; i <= n; i++)
          	   	    d[i] = -1;
 
          	   	d[s] = 0;
          	   	q.push (s);
 
          	   	while (!q.empty()){
          	   		   int u = q.front();
          	   		   q.pop();
 
          	   		   for (int id : g[u]){
          	   		   	    int v = e[id].to;
                            
                            if (d[v] == -1 && e[id].f > 0){
                            	d[v] = d[u] + 1;
                            	q.push (v);
                            }
          	   		   }
          	   	}
 
          	   	return d[t] != -1;
          }
          
 
          T dfs (int u, T flow = INF){
                 if (u == t)
                 	 return flow;
 
                 for (; pt[u] < (int)g[u].size(); pt[u]++){
                 	  int id = g[u][pt[u]];
                 	  int v = e[id].to;
 
                 	  if (d[u] + 1 != d[v] || e[id].f == 0)
                 	  	  continue;
 
                 	  	T pushed = dfs (v, min(flow, e[id].f));
                 
                        if (pushed > 0){
                        	e[id].f -= pushed;
                        	e[id ^ 1].f += pushed;
                        	return pushed; 
                        }
                 }  
 
                 return 0;	   
          }
 
          T getMaxFlow (){
          	     T ans = 0;
          	     
          	     while (1){
                        if (!bfs())
                        	break;
 
                        for (int i = 1; i <= n; i++)
                             pt[i] = 0;
 
                        T f;
                        while ((f = dfs(s)))
                               ans += f;      	 
          	     }
 
          	     return ans; 
          }
 
          void dfss (int nd, int p){
               ss[p].push_back (nd);
               m1[nd] = true;
               for (int nh : v[nd])
                    if (!m1[nh])
                        dfss (nh, p);
          }
 
          void print(int n){
               for (auto a : e)
                    if (m[a.from][a.to] && a.from != s && a.to != t && a.f == 0){
                        //printf ("%d %d\n", a.from, a.to);
                        v[a.from].push_back (a.to);
                        v[a.to].push_back (a.from);
                    }
               
               for (int i = 1; i <= n; i++){
                    if (m1[i]) continue;
                    dfss(i, can++);
               } 
 
               printf ("%d\n", can);
               for (int i = 0; i < can; i++){
                    printf ("%d", (int)ss[i].size());
                    for (int v : ss[i])
                         printf (" %d", v);
                    printf ("\n");   
               }
          }
 
}
 
int n;
 
int main(){
    
    P[2] = true;
    for (int i = 3; i <= 20000; i+=2){
         P[i] = true;
         for (int64 j = 2; j*j <= i; j++)
              if (i%j == 0){
                  P[i] = false;
                  break;
              }
    }
	  
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         if (A[i]%2==1) {
             //printf("%d %d\n", A[i], i);
             imp.push_back (i);
           }
          else{
             par.push_back (i);   
         }
        // printf ("%d\n", A[i]);     
    }
 
    Dinic::init (1000, F, S);
 
    for (int i : imp)
         Dinic::addEdge (F, i, 2);
 
    for (int i : par)
         Dinic::addEdge (i, S, 2);      
 
    for (int i : imp){
         for (int j : par){
              if (P[ A[i]+A[j] ])
                  Dinic::addEdge (i, j, 1);
         }
    }
    
   // printf ("%d\n", Dinic::getMaxFlow());
 
    if (Dinic::getMaxFlow() != n){
        printf ("Impossible\n");
        return 0;
    }
    else{
     // printf ("No\n");
        Dinic::print (n);
    }
 
	  return 0;
}