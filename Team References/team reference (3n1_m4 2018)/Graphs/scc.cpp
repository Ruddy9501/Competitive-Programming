/* Strong Connected Components
 * Outline:
 * >> Kepp tracks of what vertex belongs
 * to whom SCC, and vice-versa.
 * >> Components are stored in reverse
 * topological order.
 * */
int deg[N],dt[N],cmp[N],t=0,cc=0;
bool mk[N];
vector<int> g[N], comp[N];
inline void eadd(int u,int v)
{g[u].pb(v);}
stack<int> stk;
int scc(int u)
{
  int lw=dt[u]=++t;
  stk.push(u);
  mk[u]=true;
  for(int v: g[u])
    if(!dt[v])
    {
      int nl=scc(v);
      lw=min(lw,nl);
    }else if(mk[v])
      lw=min(lw,dt[v]);
  if(dt[u]==lw)
  {
    ++cc;
    while(stk.top()!=u)
    {
      cmp[stk.top()]=cc;
      comp[cc].pb(stk.top());
      mk[stk.top()]=false;
      stk.pop();
    }
    cmp[stk.top()]=cc;
    comp[cc].pb(stk.top());
    mk[stk.top()]=false;
    stk.pop();
  }
  return lw;
}
