/*
2018-10-16 05:49:08
https://codeforces.com/contest/588/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5 + 5;
const int N = 1e5;
 
int n, m, q, x, y, k, l[MAX], lg[MAX], p[MAX][20];
vector <int> g[MAX], v[MAX];
 
void dfs_lca (int u, int lev = 1, int pt = 0){
     p[u][0] = pt;
     l[u] = lev;
     for (int v : g[u])
          if (v != pt)
              dfs_lca (v, lev+1, u);
}
 
void init_lca (){
     dfs_lca (1);
     for (int i = 1; i <= n; ++i)
          lg[i] = log2 (i);
 
     for (int j = 1; (1 << j) <= n; ++j)
          for (int i = 1; i <= n; ++i)
               p[i][j] = p[p[i][j - 1]][j - 1];
}
 
int lca (int a, int b){
    if (l[a] < l[b])
        swap (a, b);
 
    for (int i = lg[l[a]]; i >= 0; --i)
         if (l[a] - (1<<i) >= l[b])
             a = p[a][i];
 
    if (a == b) return a;
 
    for (int i = lg[l[a]]; i >= 0; --i)
         if (p[a][i] && p[a][i] != p[b][i])
             a = p[a][i], b = p[b][i];
 
    return p[a][0];
}
 
struct node{
       int v, l, r;
       node (int v, int l, int r) : v (v), l (l), r (r) {}
};
 
node null (0, 0, 0);
vector <node> St;
int root[MAX];
 
int build (int st, int nd){
 
    if (st == nd){
        St.push_back (null);
        return (int) St.size () - 1;
    }
 
    int piv = (st+nd) >> 1;
    int l = build (st, piv);
    int r = build (piv+1, nd);
 
    St.push_back ({0, l, r});
    return (int) St.size () - 1;
}
 
int update (int x, int st, int nd, int pos){
 
    if (st > pos || nd < pos) return x;
 
    if (st == nd){
        St.push_back ({1, 0, 0});
        return (int) St.size () - 1;
    }
 
    int piv = (st+nd) >> 1;
    int l = update (St[x].l, st, piv, pos);
    int r = update (St[x].r, piv+1, nd, pos);
 
    St.push_back ({St[l].v+St[r].v, l, r});
    return (int) St.size () - 1;
}
 
void dfs (int nd, int pd=0){
 
     root[nd] = root[pd];
     for (int u : v[nd])
          root[nd] = update (root[nd], 1, N, u);
 
     for (int u : g[nd])
          if (u != pd)
              dfs (u, nd);
}
 
int query (int x, int y, int z, int w, int st, int nd, int k, int lc){
 
    int can = St[St[x].l].v + St[St[y].l].v - St[St[z].l].v - St[St[w].l].v;
    int can1 = St[x].v + St[y].v - St[z].v - St[w].v;
    int piv = (st+nd) >> 1;
    //printf ("%d %d %d %d %d\n", st, nd, can, can1, k);
 
    if (st == nd){
        if (k == 1 && can1 == 1) return st;
        return -1;
    }
 
 
    if (can >= k) return query (St[x].l, St[y].l, St[z].l, St[w].l, st, piv, k, lc);
 
    return query (St[x].r, St[y].r, St[z].r, St[w].r, piv+1, nd, k-can, lc);
}
 
int main(){
 
    scanf ("%d%d%d", &n, &m, &q);
    for (int i =1 ; i < n; ++i){
         scanf ("%d%d", &x, &y);
         g[x].push_back (y);
         g[y].push_back (x);
    }
 
    for (int i = 1; i <= m; ++i){
         scanf ("%d", &x);
         v[x].push_back (i);
    }
 
    init_lca ();
 
    St.push_back (null);
    root[0] = build (1, N);
    dfs (1, 0);
 
    while (q--){
           scanf ("%d %d %d", &x, &y, &k);
           int lc = lca (x, y);
           vector <int> sol;
           //printf ("-- %d\n", lc);
           for (int i = 1; i <= k; ++i){
                int s = query (root[x], root[y], root[lc], root[p[lc][0]], 1, N, i, lc);
               // printf ("----- %d\n", s);
                if (s == -1) break;
                sol.push_back (s);
           }
 
           printf ("%d",(int)sol.size ());
           for (int i = 0; i < (int)sol.size (); ++i)
                printf (" %d", sol[i]);
           printf ("\n");
    }
 
    return 0;
}