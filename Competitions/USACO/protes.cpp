/*
USACO
*/
 # include <cstdio>
 # include <algorithm>
 # define MOD 1000000009
 using namespace std;

 int sum[100005], s, n, P, a[100005];

 struct ABI{
    int T[100005];

    void update(int p, int v){
        for(int i = p+1; i <= P; i += i & -i)
            T[i] = (T[i]+v)%MOD;
    }

    int query(int p){
        int sol = 0;
        for(int i = p+1; i > 0; i -= (i & -i))
            sol = (sol+T[i])%MOD;
        return sol;
    }
 }A;

 int search(int val){
    return lower_bound(sum, sum+P, val)-sum;
 }

 int main(){

    freopen("protest.in", "r", stdin);
    freopen("protest.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]),
        sum[i] = a[i]+sum[i-1];
    }

    sort(sum, sum+n+1);
    P = n+1;
    A.update(search(0), 1);
    int su = 0;

    for(int i = 1; i <= n; i++){
        su += a[i];

        s = A.query(search(su));
        A.update(search(su), s);

    }

    printf("%d", s);
  return 0;
 }
