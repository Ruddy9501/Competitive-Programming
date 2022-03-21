int pp[N][19], lv[N];
ll cost[N][19];
// construir el lca del arbol T
void blca(vector<vector<pair<ll,int>>> &T)
{
  queue<int> q;
  q.push(1);
  while(sz(q))
  {
    int u = q.front();
    q.pop();
    
    for(auto &to: T[u])
    {
      if(to.sc == pp[u][0])continue;
      lv[to.sc] = lv[u] + 1;
      cost[to.sc][0] = to.fr;
      pp[to.sc][0] = u;
      q.push(to.sc);
    }
  }
  
  
  for(int i=1;i<19;++i)
    for(int j=1;j<sz(T);++j)
      pp[j][i] = pp[pp[j][i-1]][i-1],
      cost[j][i] = cost[j][i-1] + cost[pp[j][i-1]][i-1];
}
// distancia u -- v en el arbol
ll distT(int u,int v)
{
  ll res=0;
  if(lv[u] < lv[v]) swap(u,v);
  for(int i=18;~i;--i)
    if(lv[pp[u][i]] >= lv[v])
    {
      res += cost[u][i];
      u = pp[u][i];
    }
  if(u == v) return res;
  assert(lv[u] == lv[v]);
  for(int i=18;~i;--i)
    if(pp[u][i] != pp[v][i])
    {
      res += cost[u][i];
      res += cost[v][i];
      u = pp[u][i];
      v = pp[v][i];
    }
  res += cost[u][0];
  res += cost[v][0];
  return res;
}
