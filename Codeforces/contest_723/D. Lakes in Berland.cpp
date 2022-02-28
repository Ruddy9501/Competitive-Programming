/*
2016-10-03 21:43:08
https://codeforces.com/contest/723/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> par;
 
queue <par> Q;
 
struct dos{
       int id, can;
       bool operator <(const dos &R)const{
            return can < R.can;
       }
}C[1000005];
int M[1005][1005];
char S[1005][1005];
bool m[1000005];
int f, c, F, C1, nf, nc, id, K;
 
const int mf[] = {0, 0, 1, -1},
          mc[] = {-1,1,0, 0};
bool mar;
int bfs(int f, int c, int id){
    M[f][c] = id;
    Q.push(par(f, c));
    int can = 1;mar = false;
    while (!Q.empty()){
           f = Q.front().first;
           c = Q.front().second;
           Q.pop();
        for (int i = 0; i < 4; i++){
             nf = mf[i] + f;
             nc = mc[i] + c;
             if (nf < 0 || nc < 0 || nf >= F || nc >= C1){
                 mar = true;
                 continue;
             }
             if (S[nf][nc] != '.' || M[nf][nc] > 0) continue;
             Q.push(par(nf, nc));
             M[nf][nc] = id;
             can++;
        }
    }
 
    return can;
}
 
int main(){
 
    cin >> F >> C1 >> K;
    for (int i = 0; i < F; i++)
         cin >> S[i];
 
    int t, c = 0;
    for (int i = 0; i < F; i++)
         for (int j = 0; j < C1; j++){
              if (S[i][j] == '.' && !M[i][j]){
                 t = bfs(i,j,++id);
 
                  C[++c].id = id;
                  C[c].can = t;
                  if (mar) c--;
              }
         }
 
    //for (int i = 1; i <= id; i++) cout << C[i].id <<" "<<C[i].can<<endl;
    sort (C+1, C+c+1);int sol = 0;
    for (int i = 1; i <= c-K; i++){
        /* if (K <= 0) break;
         K -= C[i].can;*/
         sol += C[i].can;
         m[C[i].id] = true;
    }
 
cout << sol << endl;
    for (int i = 0; i < F; i++){
         for (int j = 0; j < C1; j++){
              if (M[i][j]){
                  if (m[M[i][j]]) cout << "*";
                   else cout << S[i][j];
              }
              else cout << S[i][j];
         }
         cout << endl;
    }
 
    return 0;
}