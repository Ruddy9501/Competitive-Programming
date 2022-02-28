/*
USACO 2016 December Contest, Gold
Problem 2. Cow Checklist
Ruddy Guerrero Alvarez
*/

#include <bits/stdc++.h>
#define RAN 1005
#define ll long long
using namespace std;

int h, g;
ll X[RAN*2], Y[RAN*2];
ll Dp[RAN][RAN][3];
const ll oo = 1ll<<50;

ll dis(ll x1, ll y1, ll x2, ll y2){
       return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int h, g;scanf ("%d %d", &h, &g);
    for (int i = 1; i <= h+g; i++)
         scanf ("%lld %lld", &X[i], &Y[i]);

    for (int i = 0; i <= h; i++)
         for (int j = 0; j <= g; j++)
              Dp[i][j][0] = Dp[i][j][1] = oo;

    Dp[1][0][0] = 0ll;
    for (int i = 1; i < h; i++)
         for (int j = 0; j <= g; j++){
              Dp[i+1][j][0] = min (Dp[i+1][j][0], Dp[i][j][0] + dis(X[i], Y[i], X[i+1], Y[i+1]));
              Dp[i+1][j][0] = min (Dp[i+1][j][0], Dp[i][j][1] + dis(X[h+j], Y[h+j], X[i+1], Y[i+1]));
              Dp[i][j+1][1] = min (Dp[i][j+1][1], Dp[i][j][0] + dis(X[i], Y[i], X[h+j+1], Y[h+j+1]));
              Dp[i][j+1][1] = min (Dp[i][j+1][1], Dp[i][j][1] + dis(X[h+j], Y[h+j], X[h+j+1], Y[h+j+1]));
         }

    printf ("%lld\n", Dp[h][g][0]);

    return 0;
}
