//~ HLD+SegmentTreeMin
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INIT ios_base::sync_with_stdio(false);\
             cin.tie(0),cout.tie()
#define endl '\n'
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ers erase
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define unique(x) (x).resize(unique(all(x))-(x).begin())
#define debug(_fmt,...) \
fprintf(stderr,"("#__VA_ARGS__ ") = (" _fmt")\n",__VA_ARGS__)

template<typename T>
void printVector(vector<T> &v)
{
  for(T &x: v)cerr << x << ' ';
  cerr << endl;
}
// testeado en http://www.codeforces.com/contest/1023/problem/F
struct SegmentTreeMin
{
  int n,nolazy;
  vector<int> data, tree, lazy;
  SegmentTreeMin(vector<int>& data, int nolazy)
    : n(sz(data)), nolazy(nolazy), data(data), tree(4*(n+1)),
        lazy(4*(n+1), nolazy){}

  #define lf(i) ((i) << 1)
  #define rg(i) (((i) << 1) | 1)

  void build(int i=1,int lo=1,int hi=-1)
  {
    if(hi==-1)hi=n;
    lazy[i] = nolazy;
    if(lo == hi){tree[i] = data[lo-1];return;}
    int m = (lo+hi) >> 1;build(lf(i), lo, m);build(rg(i), m+1,hi);
    tree[i] = min(tree[lf(i)], tree[rg(i)]);
  }

  void prop(int i,int lo,int hi)
  {
    tree[i] = min(lazy[i],tree[i]);
    if(lo != hi)
      lazy[lf(i)] = min(lazy[lf(i)], lazy[i]),
      lazy[rg(i)] = min(lazy[rg(i)], lazy[i]);
    lazy[i] = nolazy;
  }

  void update(int x,int y,int val,int i=1,int lo=1,int hi=-1)
  {
    if(hi==-1)hi=n;
    prop(i,lo,hi);
    if(x > hi || y < lo) return;
    if(x <= lo && hi <= y){lazy[i] = min(val, lazy[i]);return;}
    int m=(lo+hi) >> 1;
    update(x,y,val,lf(i),lo,m);update(x,y,val,rg(i),m+1,hi);
    tree[i] = min(tree[lf(i)], tree[rg(i)]);
  }

  int query(int x,int y,int i=1,int lo=1,int hi=-1)
  {
    if(hi==-1)hi=n;
    prop(i,lo,hi);
    if(x > hi || y < lo) return nolazy;
    if(x <= lo && hi <= y)return tree[i];
    int m=(lo+hi) >> 1;
    return min( query(x,y,lf(i),lo,m),query(x,y,rg(i),m+1,hi) );
  }
};

// testeado en http://www.codeforces.com/contest/1023/problem/F
typedef vector<vector<int>> graph;
struct HLD
{
  int n;
  graph g; // 0 - indexed
  vector<vector<int>> paths;
  vector<int> par,nxt,depth,ppos,pid;
  vector<SegmentTreeMin> ST;

  HLD(graph &g, vector<int> &d)
    : n(sz(g)),g(g),par(n),nxt(n),depth(n),ppos(n),pid(n)
  {
    dfs(); // si g es un bosque, correr dfs en cada arbol 
    for(int i=0;i<n;++i)
      if(par[i]==-1||nxt[par[i]]!=i)
      {
        paths.eb();
        vector<int> data;
        for(int j=i;~j;j=nxt[j])
        {
          paths.back().pb(j);
          ppos[j] = sz(paths.back()) - 1;
          pid[j] = sz(paths) - 1;
          data.pb(d[j]);
        }
        ST.eb(data,2e9);
        ST.back().build();
      }
  }

  int dfs(int u=0,int p=-1)
  {
    par[u] = p;
    int sz=1,mxsz=-1;
    nxt[u]=-1;
    for(int v: g[u])
    {
      if(v == p) continue;
      depth[v] = depth[u]+1;
      int tmp = dfs(v,u);
      if(tmp > mxsz)
      {
        nxt[u] = v;
        mxsz = tmp;
      }
      sz+=tmp;
    }
    return sz;
  }

  inline int root(int u)
  {return paths[pid[u]].front();}
  void update(int u,int v,int val)
  {
    while(pid[u] != pid[v])
    {
      if(depth[root(u)] < depth[root(v)])swap(u,v);
      ST[pid[u]].update(1,ppos[u]+1,val);
      u=par[root(u)];
    }
    if(depth[u] < depth[v])swap(u,v);
    v=nxt[v];
    ST[pid[u]].update(ppos[v]+1,ppos[u]+1,val);
  }

  int query(int u,int v)
  {
    int ret = 2e9;
    if(u == v) return ret; // no such path from u to v
    while(pid[u] != pid[v])
    {
      if(depth[root(u)] < depth[root(v)])swap(u,v);
      ret=min(ret, ST[pid[u]].query(1,ppos[u]+1));
      u=par[root(u)];
    }
    if(depth[u] < depth[v])swap(u,v);
    v=nxt[v];
    ret = min(ret, ST[pid[u]].query(ppos[v]+1,ppos[u]+1));
    return ret;
  }
};

void rec(vector<vector<pii>> &g, vector<int> &d, int u=0,int p=-1)
{
  for(pii &to: g[u])
  {
    if(to.sc == p) continue;
    d[to.sc] = to.fr;
    rec(g,d,to.sc,u);
  }
}

int main()
{
  #ifdef OJUDGE
    //~ freopen("in","r",stdin);
  #endif
  //~ INIT;

  int n;cin >> n;
  graph g(n);
  vector<vector<pii>> g1(n);
  for(int i=1;i<n;++i)
  {
    int u,v,c;
    cin >> u >> v >> c;
    --u,--v;
    g[u].pb(v);
    g[v].pb(u);

    g1[u].eb(c,v);
    g1[v].eb(c,u);
  }
  vector<int> d(n,2e9);
  rec(g1,d);

  HLD H(g,d);

  while(1)
  {
    int op;
    cin >> op;
    if(op == -1) break;
    if(op == 1)
    { // update
      int u,v,c;
      cin >> u >> v >> c;
      --u,--v;
      H.update(u,v,c);
    }else
    {
      int u,v;
      cin >> u >> v;
      --u,--v;
      cout << H.query(u,v) << endl;
    }
  }

  return 0;
}
/*
5
1 2 10
1 3 10
2 4 2
4 5 10

5
1 2 3
2 5 4
2 3 2
3 4 1
*/
