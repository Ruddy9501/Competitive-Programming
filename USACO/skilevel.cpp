/*
Ruddy Guerrero u Rafael
USACO/2013-2014/enero/oro
Kruskal
*/
 # include <cmath>
 # include <cstdio>
 # include <algorithm>
 # define RANG 2*500*500
 using namespace std;

 const int
    mx[] = {0, 1},
    my[] = {1, 0};

 long long Id[RANG], R[RANG], S[RANG], map[505][505], Ref[505][505], sol;
 int n, m, i, x, j, k, c, n1, n2;


 struct par {
    int x, y, d, m;
    bool operator < (const par &a)const{
        return d < a.d;
    }
 }A[RANG];

 int find_set(int x){
    if(x == Id[x])return x;
    return Id[x] = find_set(Id[x]);
 }

 long long find_val(int x){
    if(x == Id[x])return S[x];
    return max(S[x], find_val(Id[x]));
 }


 void join_set(int x, int y){
     if(R[x] >= k && R[y] >= k)
        return;

     if(R[x] >= k && R[y] < k){
        R[y] += R[x];
        S[y] = A[i].d;
     }

     if(R[y] >= k && R[x] < k){
        R[x] += R[y];
        S[x] = A[i].d;
     }

     if(R[x] < k && R[y] < k){
        if(R[x] > R[y]){
            R[x] += R[y];
            Id[y] = x;
            S[x] = A[i].d;
        }
        else {
            R[y] += R[x];
            Id[x] = y;
            S[y] = A[i].d;
        }
     }
 }

 int main(){

     freopen("skilevel.in", "r", stdin);
     freopen("skilevel.out", "w", stdout);

    scanf("%d %d %d", &n, &m, &k);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++){
            scanf("%d", &map[i][j]);
            Ref[i][j] = ++c;
            Id[c] = c;
            R[c] = 1;
        }

    c = 0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++){
            if(j+1 <= m) A[++c] = (par){i, j, abs(map[i][j]-map[i][j+1]), 0};
            if(i+1 <= n) A[++c] = (par){i, j, abs(map[i][j]-map[i+1][j]), 1};
        }

    sort(A+1, A+c+1);

    for(i = 1; i <= c; i++){
        n1 = find_set(Id[Ref[A[i].x][A[i].y]]);
        n2 = find_set(Id[Ref[A[i].x+mx[A[i].m]][A[i].y+my[A[i].m]]]);
        if(n1 != n2){
            join_set(n1, n2);
        }
    }

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++){
            scanf("%d", &x);
            if(x) sol += find_val(Ref[i][j]);
        }

    printf("%lld", sol);

 }
