/*
2017-06-26 03:35:59
https://codeforces.com/contest/821/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
#define int64 long long
#define oo 1 << 30
 
struct par{
       int x, y, cos;
       par(int a, int b, int c){
           x = a;
           y = b;
           cos = c;
       }
       bool operator<(const par &R)const{
            return R.cos < cos;
       }
};
 
const int mx[] = {0,0,1,-1},
          my[] = {1,-1,0,0};
 
const int RAN = 1e4+5;
int n,m,k,x,y;
map <pair <int, int>, int> C;
bitset <RAN> M[RAN];
priority_queue <par> Q;
 
int main(){
 
    scanf ("%d%d%d",&n,&m,&k);
    C[make_pair(n,m)] = oo;
    while (k--){
           scanf ("%d%d",&x,&y);
           M[x][y] = 1;
           C[make_pair(x,y)] = oo;
    }
 
    C[make_pair(1,1)] = 0;
    Q.push(par(1, 1, 0));
    //Q.push(par(1, 1, 1));
 
    while (!Q.empty()){
           x = Q.top().x;
           y = Q.top().y;
           int cos =  Q.top().cos;// printf ("%d\n", cos);
           Q.pop();
 
           for (int i = 0; i < 4; i++){
                int nx = mx[i] + x;
                int ny = my[i] + y;
                if (M[nx][ny] && C[make_pair(nx, ny)] > cos){
                    C[make_pair(nx, ny)] = cos;
                    Q.push(par(nx, ny, cos));
                }
           }
 
           int j = y;
           for (int ii = 1; ii <= n; ii++){
                if (M[ii][j] || (ii == n && j == m))
                     if (C[make_pair(ii, j)] > cos + 1){
                         C[make_pair(ii, j)] = cos + 1;
                         Q.push(par(ii, j, cos+1));
                     }
 
                if (M[ii][j+1] || (ii == n && j+1 == m))
                    if (C[make_pair(ii, j+1)] > cos + 1){
                         C[make_pair(ii, j+1)] = cos + 1;
                         Q.push(par(ii, j+1, cos+1));
                     }
 
                if (j-1 > 0 && M[ii][j-1])
                    if (C[make_pair(ii, j-1)] > cos + 1){
                         C[make_pair(ii, j-1)] = cos + 1;
                         Q.push(par(ii, j-1,cos+1));
                     }
 
                if (M[ii][j+2])
                    if (C[make_pair(ii, j+2)] > cos + 1){
                        C[make_pair(ii, j+2)] = cos + 1;
                        Q.push(par(ii, j+2,cos+1));
                     }
 
                if (j-2 > 0 && M[ii][j-2])
                    if (C[make_pair(ii, j-2)] > cos + 1){
                        C[make_pair(ii, j-2)] = cos + 1;
                        Q.push(par(ii, j-2,cos+1));
                     }
          }
 
          int i = x;
          for (int jj = 1 ; jj <= m; jj++){
                if (M[i][jj] || (i == n && jj == m))
                     if (C[make_pair(i, jj)] > cos + 1){
                         C[make_pair(i, jj)] = cos + 1;
                         Q.push(par(i, jj,cos+1));
                     }
 
                if (M[i+1][jj] || (i+1 == n && jj == m))
                    if (C[make_pair(i+1, jj)] > cos + 1){
                         C[make_pair(i+1, jj)] = cos + 1;
                         Q.push(par(i+1, jj,cos+1));
                     }
 
                if (i-1 > 0 && M[i-1][jj])
                    if (C[make_pair(i-1, jj)] > cos + 1){
                         C[make_pair(i-1, jj)] = cos + 1;
                         Q.push(par(i-1, jj,cos+1));
                     }
 
                if (M[i+2][jj])
                    if (C[make_pair(i+2, jj)] > cos + 1){
                        C[make_pair(i+2, jj)] = cos + 1;
                        Q.push(par(i+2, jj, cos+1));
                     }
 
                if (i-2 > 0 && M[i-2][jj])
                    if (C[make_pair(i-2, jj)] > cos + 1){
                        C[make_pair(i-2, jj)] = cos + 1;
                        Q.push(par(i-2, jj, cos+1));
                     }
          }
    }
 
   /* for (int i = 1; i <= n; i++){
         for (int j = 1; j <= m; j++)
              printf ("%d ", C[make_pair(i, j)]);
         printf ("\n");
    }*/
 
    int sol = C[make_pair(n,m)];
 
    if (sol == oo) printf ("-1\n");
     else printf ("%d\n", sol);
 
    return 0;
}