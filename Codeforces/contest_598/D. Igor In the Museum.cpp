/*
2015-11-13 19:55:29
https://codeforces.com/contest/598/problem/D
*/
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
 
using namespace std;
typedef pair<int, int>par;
const int mx[] = {-1, 1, 0, 0},
          my[]  ={ 0, 0,  1, -1};
 
int F, C,x,y,nx,ny,c, q, v, S[1005][1005];
int M[1005][1005], M1[1005][1005], M3[1005][1005], M4[1005][1005];
char A[1005][1005];
queue <par> Q;
 
int bfs1(int x, int y){
    Q.push(par(x, y));
    c++;
    int s = 0;
    M[x][y] = true;
    while (!Q.empty()){
           x = Q.front().first;
           y = Q.front().second;
           Q.pop();
           for (int i = 0; i < 8; i++){
                nx = mx[i]+x;
                ny = my[i]+y;
                if (nx < 0 || nx >= F || ny < 0 || ny >= C) continue;
                if (!M[nx][ny] && A[nx][ny]=='.'){
                    M[nx][ny] = c;
                    Q.push(par(nx,ny));
                }
                if (A[nx][ny]=='*')s++;
           }
    }
    return s;
}
 
 
int bfs2(int x, int y, int v){
    Q.push(par(x, y));
    M1[x][y] = true;
    S[x][y] = v;
    while (!Q.empty()){
           x = Q.front().first;
           y = Q.front().second;
           Q.pop();
           for (int i = 0; i < 8; i++){
                nx = mx[i]+x;
                ny = my[i]+y;
                if (nx < 0 || nx >= F || ny < 0 || ny >= C) continue;
                if (!M1[nx][ny] && A[nx][ny]=='.'){
                    S[nx][ny] = v;
                    M1[nx][ny] = true;
                    Q.push(par(nx,ny));
                }
           }
    }
}
 
int main()
{
   cin >> F >> C >> q;
   for (int i = 0; i < F; i++)
        cin >> A[i];
 
   for (int i = 0 ; i < F; i++)
        for (int j = 0 ; j < C; j++)
        if (!M[i][j] && A[i][j] == '.'){
            int val = bfs1 (i, j);
            bfs2 (i, j, val);
        }
 
   while (q--){
         cin >> x>>y;
         x--, y--;
        cout << S[x][y]<<endl;
   }
 
   return 0;
}