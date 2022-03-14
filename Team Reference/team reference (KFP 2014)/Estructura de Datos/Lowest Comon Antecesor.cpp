# include <bits/stdc++.h>
 # define RANG 1000005
 using namespace std;

 int i, cn, q, x, y;
 vector <int> v[RANG];

 struct LCA {
    int T[100005][20], L[100005];

    void DFS(int np, int prev){
        L[np] = L[prev]+1;
        int l = v[np].size();
        for(int i = 0; i < l; i++){
            int nh = v[np][i];
            if(nh != prev)
                DFS(nh, np);
        }
     }

    void BFS(int np){
        queue <int> Q;
        Q.push(np);
        L[np] = 1;
        int l, nh;
        while(!Q.empty()){
            np = Q.front();
            Q.pop();

            l = v[np].size();
            for(int i = 0; i < l; i++){
                nh = v[np][i];
                if(L[nh] == 0){
                    L[nh] = L[np]+1;
                    Q.push(nh);
                }
            }
        }
    }

    void Build(int n){
        BFS(1);
        int lg = log2(n);
        for(int j = 1; j <= lg; j++)
            for(int i = 1; i <= n; i++)
                if(T[i][j-1] != -1)
                    T[i][j] = T[T[i][j-1]][j-1];
    }

     int Query(int x, int y){
        int sol = 0;
        if(L[x] < L[y])swap(x, y);

        int lg = (int)log2(L[x]);
        for(int i = lg; i >= 0; i--)
            if(L[x] - (1 << i) >= L[y] && T[x][i])
                x = T[x][i], sol += (1 << i);

        if(x == y)return sol;

        for(int i = lg; i >= 0; i--)
            if(T[x][i] != T[y][i] && T[x][i])
                x = T[x][i], y = T[y][i], sol += (1 << i);

        return sol+2;
        return T[x][0];
     }
 }Lc;

 int main(){

     scanf("%d", &cn);
     for(i = 2; i <= cn; i++){//Leyendo padre
        scanf("%d", &Lc.T[i][0]);
        v[Lc.T[i][0]].push_back(i);
     }

    Lc.Build(cn);
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &x, &y);
        printf("%d\n", Lc.Query(x, y));
    }
