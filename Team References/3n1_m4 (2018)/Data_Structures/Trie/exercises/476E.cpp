//~ 476E - codeforces
/* Replace each string with its non-empty
 * prefix, s.t. the new strings are still
 * unique and minimizes the total length.
 * 
 * Note: solution uses a smaller to large
 * technique.
 */
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INIT ios_base::sync_with_stdio(false);\
             cin.tie(0),cout.tie();
#define endl '\n'
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ins insert
#define ers erase
#define sz(c) (c).size()
#define all(x) (x).begin(),(x).end()
#define unique(x) (x).resize(unique(all(x))-(x).begin())

struct trie {
  bool mk;
  trie* next[0x100];
  trie() { fill(next, next+0x100, nullptr);mk=false;}
};

trie* wadd(string& s, trie* r)
{
  for(char c: s)
  {
    if(r->next[c] == nullptr)
      r->next[c] = new trie;
    r = r->next[c];
  }
  r->mk=true;
  return r;
}
trie* root=new trie;

vector<multiset<int>> ss;
int js(int u,int v)
{
  if(u==v)return u;
  if(sz(ss[u]) < sz(ss[v]))
    swap(u,v);
  ss[u].ins(all(ss[v]));
  return u;
}
int dfs(trie* r,int len=0)
{
  int my=ss.size();
  ss.pb(multiset<int>());
  
  for(char c='a';c<='z';++c)
  {
    if(r->next[c]==nullptr)continue;
    int nn=dfs(r->next[c],len+1);
    my = js(my,nn);
  }
  
  if(!r->mk)
  {
    if(!ss[my].empty())
    {
      auto tmp = ss[my].end();--tmp;
      ss[my].ers(tmp);
      ss[my].ins(len);
    }
  }else ss[my].ins(len);
  
  return my;
}

int main()
{
  INIT
  int n;cin>>n;
  for(int i=1;i<=n;++i)
  {
    string s;
    cin>>s;
    wadd(s,root);
  }

  root->mk=true;
  int id = dfs(root);

  int ans=0;
  for(int x: ss[id])
    ans+=x;
  
  cout<<ans<<endl;  
  return 0;
}
