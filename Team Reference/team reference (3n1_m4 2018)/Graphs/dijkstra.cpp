struct Edge
{
  int u,v;
  ll w;
  Edge(){}
  Edge(int u,int v,int w): u(u), v(v), w(w){}
  int nxt(int x){return x==u?v:u;}
};
const ll inf = numeric_limits<ll>::max();
/* funcion dijkstra:
 * g: grafo, dist: distancias minimas, st: nodo inicial
 */
void dijkstra(vector<vector<Edge*>> &g, vector<ll> &dist, int st)
{
  dist.resize(sz(g), inf);
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
  dist[st] = 0;
  pq.emplace(0, st);
  while(sz(pq))
  {
    int u = pq.top().sc;
    ll ct = pq.top().fr;
    pq.pop();
    if(dist[u] != ct) continue;
    dist[u] = ct;
    for(Edge* &to: g[u])
    {
      int v = to->nxt(u);
      if(dist[v] > dist[u] + to->w)
      {
        dist[v] = dist[u] + to->w;
        pq.emplace(dist[v], v);
      }
    }
  }
}
// modo de empleo, m - tot. aristas, n - tot. nodos
vector<Edge> G(m);
vector<vector<Edge*>> g(n+1);
for(Edge &e: G) g[e.u].eb(&e), g[e.v].eb(&e);
