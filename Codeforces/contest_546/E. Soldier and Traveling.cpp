/*
2017-10-13 15:47:02
https://codeforces.com/contest/546/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
namespace Dinic{
       
          typedef int T;
 
          struct edge{
                 int from, to;
                 T f, c;
          };
 
          const int MAX = 5e2 + 5;
          const T INF = INT_MAX;
 
          int n, s, t, pt[MAX], d[MAX], S[MAX][MAX];
          vector <edge> e;
          vector <int> g[MAX];
          queue <int> q;
 
          void init (int n_, int s_, int t_){
          	   n = n_, s = s_, t = t_;
 
          	   for (int i = 1; i <= n; i++)
          	   	    g[i].clear();
          	   	e.clear ();
          }
 
          void addEdge (int from, int to, T c){
          	   edge ed;
          	   ed.from = from, ed.to = to, ed.f = c, ed.c = c;
          	   e.push_back (ed);
          	   g[from].push_back ((int) e.size() - 1);
 
          	   ed.from = to, ed.to = from, ed.f = 0, ed.c = 0;
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
 
          void print (int n){
               
               for (int i = 1; i <= n; i++)
                    fill (S[i], S[i]+n+1, 0);
 
               for (auto v : e) {
                    int a = v.from, b = v.to;
          
                    if (a > 105) a -= 105;
                    if (b > 105) b -= 105;
                    if (v.c-v.f <= 0) continue;
                    //printf ("%d %d %d\n", a, b, (v.c-v.f));
 
 
                    S[a][b] = abs(v.c - v.f);
                   // S[v.from][v.to] = INF - v.f;
               }
 
               for (int i = 1; i <= n; i++)
                   for (int j = 1; j <= n; j++){
                        printf ("%d", S[i][j]);
                        if (j == n) printf ("\n");
                         else printf (" ");
                   }
          }
}
 
const int MAX = 1e2 + 5;
const int MAXT = 1e4 + 5;
const int INF = 1e9;
 
const int F = MAX + MAX + 1;
const int S = MAX + MAX + 2;
 
int main(){
	  
    Dinic::init (MAX + MAX + 2, F, S);
 
    int n, m;scanf ("%d %d", &n, &m);
    int tot = 0;
    for (int i = 1; i <= n; i++){
    	   int a;scanf ("%d", &a);
         Dinic::addEdge (F, i, a);
         tot += a;
    }
 
    for (int i = 1; i <= n; i++)
         Dinic::addEdge (i, i+MAX, INF);
    
    int tot1 = 0;
    for (int i = 1; i <= n; i++){
         int a; scanf ("%d", &a);
         tot1 += a;
         Dinic::addEdge (i+MAX, S, a);
    }
 
    for (int i = 0; i < m; i++){
         int a, b; scanf ("%d %d", &a, &b);
         Dinic::addEdge (a, b+MAX, INF);
         Dinic::addEdge (b, a+MAX, INF);
    }
 
    //printf ("%d %d\n", tot, tot1, Dinic::getMaxFlow ());
    
 
    if (Dinic::getMaxFlow () != tot1 || tot != tot1){
        printf ("NO\n");
        return 0;
    }
 
    printf ("YES\n");
    Dinic::print (n);
 
 
	  return 0;
}