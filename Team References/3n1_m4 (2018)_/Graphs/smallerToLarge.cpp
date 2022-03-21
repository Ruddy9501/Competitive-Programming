/* Smaller to Large. O(N(logN)^2)
 * 
 * http://codeforces.com/contest/1042/problem/F
 * ---------- F. Leaf Sets -------------------
 * Let's call some set of leaves beautiful if
 * the maximum distance between any pair of
 * leaves in it is less or equal to k. You want
 * to split all leaves into non-intersecting
 * beautiful sets. What is the minimal number
 * of sets in such a split?
 * 
 * Solution: Greedely compact for each vertex
 * the solution for it's subtree. Always taking
 * into account that we don't need each vertex
 * of a set of leafs we only need the deepest.
 */
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


const int N = 1e6+7;


int n,k;
vector<int> g[N];
int deg[N];
void eadd(int u,int v)
{
  g[u].eb(v);
  g[v].eb(u);
  ++deg[u];
  ++deg[v];
}


// smaller to large tehnique
vector<multiset<int>> ss;
int js(int x,int y)
{
  if(x == y) return x;
  if(sz(ss[x]) < sz(ss[y])) swap (x, y);
  ss[x].ins(all(ss[y]));
  return x;
}
int dfs(int u, int d=0, int p=0)
{
  int my = sz(ss);
  ss.eb();
  if(deg[u] == 1)
  {
    ss[my].ins(d);
    return my;
  }
  for(int v: g[u])
    if(v != p) my = js(my, dfs(v,d+1,u));
  
  
  vector<int> del;
  auto it = ss[my].begin();it++;
  auto jt = ss[my].begin();
  while(it != ss[my].end())
  {
    if((*jt-d) + (*it-d) <= k) del.pb(*jt);
    else break;
    jt++,it++;
  }
  for(int i: del) ss[my].ers(ss[my].find(i));
  
  
  return my;
}
// end of technique


int main()
{
  scanf("%d%d", &n, &k);
  for(int i=1;i<n;++i)
  {
    int u,v;
    scanf("%d%d", &u, &v);
    eadd(u,v);
  }
  int rt=-1;
  for(int i=1;i<=n;++i)
    if(deg[i] > 1){rt = dfs(i);break;}
  cout << sz(ss[rt]) << endl;
  
  return 0;
}
//~ f
