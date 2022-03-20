/*
2017-11-28 19:43:23
https://codeforces.com/contest/890/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5 + 5;
int n, l, c[30];
char a[MAX];
 
vector <int> g[30];
 
int T[MAX], low[MAX], c1[30], L; 
bool flag, mk[MAX], m[30], m1[30];
stack <int> S;
 
void SCC(int np){
    T[np] = low[np] = ++L;
    int l = g[np].size();
    S.push(np);
    for(int i = 0; i < l; i++){
        int nh = g[np][i];
        if(!T[nh]){
            SCC(nh);
            low[np] = min(low[nh], low[np]);
        }
        else
            if(!mk[nh])
                low[np] = min(T[nh], low[np]);
    }
 
    if(low[np] == T[np]){
		
		if (S.top() != np) flag = true;
		
        while(S.top() != np){
          //  printf("%d ", S.top());
            mk[S.top()] = true;
            S.pop();
        }
       //printf("%d\n", S.top());
        mk[S.top()] = true;
        S.pop();
    }
 }
 
string sol;
 
void dfs (int u){
      sol += ('a'+u);
      m[u] = true;
      for (int v : g[u])
          if (!m[v])
              dfs (v); 
}
 
int main(){
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
	     scanf ("%s", a);
	     
	     l = strlen (a);
	     for (int j = 1; j < l; j++)
		      g[a[j-1]-'a'].push_back (a[j]-'a');
	     
	     for (int j = 0; j < l; j++) m1[a[j]-'a'] = true, c1[a[j]-'a']++;
	     
	     for (int j = 0; j < 26; j++){
	          if (c1[j] > 1) flag = true;
		      c1[j] = 0;
		 }
	     
	}
	
	for (int i = 0; i < 26; i++){
	     sort (g[i].begin(), g[i].end());
	     auto it = unique (g[i].begin(), g[i].end());
	     g[i].erase (it, g[i].end());
	}
	
	for (int i = 0; i < 26; i++){
	     
	     if (!mk[i] && m1[i]) SCC (i);
	     
	     if ((int)g[i].size() > 1) flag = true;  
	}
	
	if (flag){
	    printf ("NO\n");
	    return 0;
	}
	
	for (int i = 0; i < 26; i++){
	     for (int j : g[i])
	          c[j]++; 
	}
	
	vector <int> v;
	for (int i = 0; i < 26; i++){
	     if (!c[i] && m1[i]) v.push_back (i);
	     if (c[i] > 1){
		     printf ("NO\n");
		     return 0;
		 }
	}
	sort (v.begin(), v.end());
	for (int i : v){
	     dfs (i);  
	}     
	
	for (int i = 0; i < (int)sol.size(); i++)
	     printf ("%c", sol[i]);
	printf ("\n");          
	
    return 0;
}