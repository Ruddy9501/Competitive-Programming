# include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;

vector <par> v[10005];
vector <int> indx[10005];
int subsize[10005], chainHead[10005], chainIndx[10005];
int posInBase[10005], otherEnd[10005], chainNo, cont;

St -> estructura segment tree. Build-Query-Update+Lazy Propagation
LC -> Lowest Common Antecesor. Level[n], T[n][log n]. Build-Query
//Inicializar Level y subsize
 void DFS(int np, int prev, int depth = 0){
    Lc.Level[np] = depth;
    Lc.T[np][0] = prev;
    subsize[np] = 1;
    int l = v[np].size();
    for(int i = 0; i < l; i++){
        int nh = v[np][i].first;
        if(nh != prev){
            otherEnd[indx[np][i]] = nh;
            DFS(nh, np, depth+1);
            subsize[np] += subsize[nh];
        }
    }
 }
//Descomposition Hevy Ligth
 void HDL(int np, int nc, int prev){
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = np;

    chainIndx[np] = chainNo;
    posInBase[np] = cont;
Posicion que sera usada en el Segment Tree
    St.elements[cont++] = nc;

    int nh = -1, newc, l = v[np].size();
    for(int i = 0; i < l; i++){
        if(v[np][i].first == prev)continue;
        if(nh == -1 || subsize[nh] < subsize[v[np][i].first]){
            nh = v[np][i].first;
            newc = v[np][i].second;
        }
    }
    if(nh != -1)
        HDL(nh, newc, np);

    for(int i = 0; i < l; i++)
        if(nh != v[np][i].first && v[np][i].first != prev){
            chainNo++;
            HDL(v[np][i].first, v[np][i].second, np);
        }

 }
  int query_up(int u, int v){
    int uchain = chainIndx[u], vchain = chainIndx[v], ans = -1;

    while(uchain != vchain){
        ans = max(ans, St.query(0, cont-1, 1, posInBase[chainHead[uchain]],
			      posInBase[u]));
        u = Lc.T[chainHead[uchain]][0];
        uchain = chainIndx[u];
    }

    ans = max(ans, St.query(0, cont-1, 1, posInBase[v]+1, posInBase[u]));

    return ans;
 }
 int query(int x, int y){
    int lca = Lc.Query(x, y);
    return max(query_up(x, lca), query_up(y, lca));
 }
 void update(int i, int val){
    int x = otherEnd[i];
    x = posInBase[x];
    St.elements[x] = val;
    St.update(0, cont-1, 1, x);
 }
 int n, i, a, b, c, tc;
 char arr[50];

 int main(){
        scanf("%d", &n);
        cont = 0;
        for(i = 1; i < n; i++){
            scanf("%d %d %d", &a, &b, &c);
            v[a].push_back((par){b, c});
            v[b].push_back((par){a, c});
            indx[a].push_back(i);
            indx[b].push_back(i);
        }

        fill(chainHead, chainHead+10002, -1);
        chainNo = 0;   
        DFS(1, -1);   
        HDL(1, -1, -1);
        St.Build(0, cont-1);     
        Lc.Build(n);
 }
