vector<int> g[N];
void eadd(int u,int v)
{
  g[u].pb(v);
  g[v].pb(u);
}
int sz[N],mc[N],p[N],q[N];
bool mk[N];
int gc(int st)
{
  int b=0,e=0;
  q[e++]=st, mc[st]=0, p[st]=-1, sz[st]=1;
  while(b<e)
  {
    int u=q[b++];
    for(auto v: g[u])
    {
      if(p[u]==v||mk[v])continue;
      p[v]=u;
      mc[v]=0;
      sz[v]=1;
      q[e++]=v;
    }
  }
  for(int i=e-1;~i;--i)
  {
    int u=q[i];
    int bc=max(e-sz[u],mc[u]);
    if(2*bc<=e)
    {
      st=u;
      break;
    }
    sz[p[u]]+=sz[u];
    mc[p[u]]=max(mc[p[u]], sz[u]);
  }
  return st;
}
void solve(int u=1)
{
  // divide
  u = gc(u);
  
  mk[u]=true;
  
  // conquer

  for(auto v: g[u])
  {
    if(mk[v])continue;
    solve(v);
  }
}
