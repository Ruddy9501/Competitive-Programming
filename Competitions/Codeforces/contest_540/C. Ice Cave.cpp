/*
2015-04-30 21:56:57
https://codeforces.com/contest/540/problem/C
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
 
using namespace std;
typedef pair<int, int>par;
 
queue <par> Q;
 
char A[1000][1000];
int f, c, ff, x, y, ii, F, I,nx, ny;
const int mx[] = {1,0,-1,0},
          my[] = {0,1,0,-1};
 
 
int main(){
 
    cin >> f >> c;
    for (int i = 1; i <= f; i++){
         for (int j = 1; j <= c; j++)
              cin >> A[i][j];
    }
 
    cin >> I >> F >> ii >> ff;
    Q.push(par(I,F));
   // A[I][F] = 'X';
    while (!Q.empty()){
           x = Q.front().first;
           y = Q.front().second;
           Q.pop();
           for (int i = 0; i < 4; i++){
                nx = mx[i] + x;
                ny = my[i] + y;
                if (nx == ii && ny == ff && A[nx][ny] == 'X'){
                    printf ("YES\n");
                    return 0;
                }
                if (A[nx][ny] == '.'){
                    A[nx][ny] = 'X';
                    Q.push(par(nx, ny));
                }
           }
    }
printf ("NO\n");
    return 0;
}