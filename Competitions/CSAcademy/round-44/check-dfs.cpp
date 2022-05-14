#include <bits/stdc++.h>

using namespace std;
const int RAN = 1e5 + 5;

bool ok = true, M[RAN];
int n, p = 0, m, a, b, A[RAN];
multiset <int> v[RAN];

void dfs (int nd, int np){
     p++;
     if (nd != A[p])
         ok = false; 

     int t = (int)v[nd].size();
     while ((int)v[nd].size() > 0){
     	    auto a = v[nd].find (A[p+1]);
     	    if (a == v[nd].end())
     	    	a = v[nd].begin();
            v[nd].erase (a);

            auto b = v[*a].find (nd);
            if (b != v[*a].end())
            	v[*a].erase (b); 
            

     	    if (M[*a]) continue;
            M[*a] = true;
     	    dfs (*a, nd); 	 
     }
}

int main(){
    
    scanf ("%d %d", &n, &m);

    for (int i= 1; i <= n; i++)
    	 scanf ("%d", &A[i]);

    for (int i = 1; i <= m; i++){
    	 scanf ("%d %d", &a, &b);
    	 v[a].insert (b);
    	 v[b].insert (a);
    }
    
    M[1] = true;
    dfs (1, -1); 
   
    if (ok) printf ("1\n");
     else printf ("0\n");

	return 0;
}