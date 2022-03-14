# include <bits/stdc++.h>
 using namespace std;

 const int oo = 1 << 30;
 int subsize[100005], Ant[100005], sol[100005], ref_pos, n, x, y;
 vector <int> v[100005];
 bool mk[100005];

 void DFS1(int np, int prev){
    subsize[np] = 1;
    int l = v[np].size();
    for(int i = 0; i < l; i++){
        int nh = v[np][i];
        if(nh != prev && !mk[nh]){
            DFS1(nh, np);
            subsize[np] += subsize[nh];
        }
    }
 }

 int DFS2(int np, int prev){

     int l = v[np].size();
     for(int i = 0; i < l; i++){
        int nh = v[np][i];
        if(nh != prev && !mk[nh] && subsize[nh] > subsize[ref_pos]/2)
            return DFS2(nh, np);
     }
     return np;
 }

 void Descomposition(int root, int prev){

    ref_pos = root;
    DFS1(root, root);
    int centroid = DFS2(root, root);
    Ant[centroid] = prev;
    mk[centroid] = true;
    int l = v[centroid].size();
    for(int i = 0; i < l; i++){
        int nh = v[centroid][i];
        if(!mk[nh])
            Descomposition(nh, centroid);
    }
 }
 // LC -> tipo LCA, buscar implementacion arriba. 

 void Update(int x){
    int y = x;
    while(y > 0){
        sol[y] = min(sol[y], Lc.Query(x, y));
        y = Ant[y];
    }
 }

 int Query(int x){
    int y = x, ans = oo;
    while(y > 0){
        ans = min(ans, Lc.Query(y, x)+sol[y]);
        y = Ant[y];
    }
    return ans;
 }
int Q;
 int main(){

    scanf("%d %d", &n, &Q);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    fill(sol, sol+n+1, oo);
    Lc.Build(n);
    Descomposition(1, -1);
    Update(1);


    while(Q--){
        scanf("%d %d", &x, &y);
        if(x == 1)
            Update(y);
        else
            printf("%d\n", Query(y));

    }
 return 0;
 }
