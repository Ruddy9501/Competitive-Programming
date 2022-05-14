#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> par;
const int MAX = 1e5 + 5;
int n, k, M[MAX], C[MAX];
vector <par> g[MAX];
vector <int> r;

void dfs1(int nd, int ant = -1, int l = 0){
	 for (auto v : g[nd]){
          if (v.first != ant){
          	  dfs1 (v.first, nd, l+1);
              C[nd] += C[v.first]; 
          }
	 }
	 C[nd]++;
}

void dfs2 (int nd, int ant = -1){
	 for (auto v : g[nd]){
	 	  if (v.first == ant) continue;
	 	  if (v.second) r.push_back (C[v.first]);
	 	   else dfs2 (v.first, nd);
	 }
}

int main(){

    scanf ("%d%d", &n, &k);
    for (int i = 1; i < n; i++){
    	 int nd, nh, a;scanf ("%d %d %d", &nd, &nh, &a);
    	 g[nd].push_back(par(nh, a));
    	 g[nh].push_back(par(nd, a));
    	// M[nh] = a;
    }

    dfs1 (1);
    dfs2 (1);
     
    sort (r.begin(), r.end());
    reverse (r.begin(), r.end());
    
    int sol = 0;
    for (int v : r){ 
    	 if (n > k){
    	 	 n -= v;
    	 	 sol++;
    	 }
    }   
    
    if (k >= n) printf ("%d\n", sol);
     else printf ("-1\n");

	return 0;
}