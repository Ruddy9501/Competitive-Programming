// 2010-2011 Bronce March
 # include <queue>
 # include <vector>
 # include <cstdio>
 # include <algorithm>
 using namespace std;

 struct par{
    int x, y;
    bool operator < (const par &a)
    const {
        if(y != a.y)return y < a.y;
        return x < a.x;
    }
 }L[105];

 vector <int> v[105];
 queue <int> Q;
 int n, m, i, x, y, j, c, np, nh, l, a[105];
 bool mk[105];

 int main(){

    freopen("pathfind.in", "r", stdin);
    freopen("pathfind.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++){
            scanf("%d", &x);
            if(x)v[i].push_back(j);
        }

    L[0] = (par){m, 0};
    mk[m] = true;
    for(Q.push(m); !Q.empty(); Q.pop()){
        np = Q.front();
        l = v[np].size();

        for(i = 0; i < l; i++){
            nh = v[np][i];
            if(!mk[nh]){
                mk[nh] = true,
                L[++c] = (par){nh, a[np]+1};
                a[nh] = a[np]+1;
                Q.push(nh);
            }
        }
    }

    sort(L, L+c+1);
    for(i = 0; i <= c; i++){
        if(i > 0 && L[i-1].y != L[i].y)
            printf("\n");
        else if(i)
            printf(" ");
        printf("%d", L[i].x);
    }
 }
