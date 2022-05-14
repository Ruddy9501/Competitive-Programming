/*
2017-11-22 17:25:11
https://codeforces.com/contest/894/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
 
const int MAX = 1e6 + 5;
int n, m, x, y, z;
 
int T[MAX], low[MAX], L, id[MAX], cc;
bool mk[MAX];
stack <int> S;
vector <int> g1[MAX];
 
 
void SCC(int np){
    T[np] = low[np] = ++L;
    int l = g1[np].size();
    S.push(np);
    for (int i = 0; i < l; i++){
         int nh = g1[np][i];
         if (!T[nh]){
             SCC(nh);
             low[np] = min(low[nh], low[np]);
         }
         else
             if (!mk[nh])
                 low[np] = min(T[nh], low[np]);
    }
 
    if (low[np] == T[np]){
		cc++;
        while (S.top() != np){
              id[S.top()] = cc;
              mk[S.top()] = true;
              S.pop();
        }
        id[S.top()] = cc;
        mk[S.top()] = true;
        S.pop();
    }
 }
 
struct tre{
       int x, y;
       int64 z; 
};
 
vector <tre> v;
 
int can[MAX];
vector <pair<int, int64> > g[MAX];
bool mar[MAX];
 
void dfs (int u){
     mar[u] = true;
     for (auto v : g[u])
          if (!mar[v.first])
              dfs (v.first);
}
 
int64 c[MAX], dp[MAX];
vector <pair<int, int64> > g2[MAX];
 
 
int main(){
		
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
	     scanf ("%d %d %d", &x, &y, &z);
         g1[x].push_back (y);
         v.push_back ((tre){x, y, z});
         //printf ("%d %d %lld\n", x, y, b);  
    }
    
    int ini;
	scanf ("%d", &ini);
	SCC (ini); 
    
    for (auto it : v){
	     x = it.x, y = it.y;
	     int64 z = it.z;
	     if (id[x] == id[y]){
			 
             int64 n = 1ll+sqrtl(1ll*(1ll+8ll*z));
             n >>= 1;
             int64 b = n*(1ll-n*n+6ll*z)/6ll;
         
	         c[id[x]] += b;
		 }
	      else
		     g[id[x]].push_back ({id[y],z});
	}
	
	dfs (id[ini]);
	
    for (int i = 1; i <= cc; i++)
         if (mar[i])
             for (auto v : g[i])
			      if (mar[v.first]){
			      //    printf ("%d %d %lld\n", i, v.first, v.second);
			          g2[i].push_back (v);
			          can[v.first]++;
			      }
    
    queue <int> Q;
    assert ((int)Q.size() != 1);
    for (int i = 1; i <= cc; i++)
         if (!can[i] && mar[i]) 
             Q.push (i);
             
    vector <int> orden;
    while (!Q.empty()){
           x = Q.front();
           Q.pop(); 
           orden.push_back (x);
           for (auto v : g2[x]){
		        can[v.first]--;
		        if (can[v.first] == 0) Q.push(v.first);
		   }
    }         
    
    for (int i = 1; i <= cc; i++) dp[i] = c[i];
    
    int64 sol = 0;
    for (int u : orden){
		 sol = max (sol, dp[u]);
	     for (auto v : g2[u]){
		      dp[v.first] = max (dp[v.first], dp[u] + c[v.first] + v.second);
		      sol = max (sol, dp[v.first]);  
	     }
	}
     
    printf ("%lld\n", sol); 
      
    return 0;
}