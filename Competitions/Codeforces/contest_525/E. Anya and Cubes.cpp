/*
2015-03-27 06:57:04
https://codeforces.com/contest/525/problem/E
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
map <long long,int> m[30];
long long n, c, K, c1;
long long F[1000], R[4000000], B[5000000], A[1000000], sol, M;
 
void solve1(int pos, long long sum, int k){
     m[k][sum]++;
 
     for (int i = pos; i <= (n+1)/2; i++){
           //solve1 (i+1,sum, k);
          if (sum+A[i] <= M) solve1 (i+1,sum+A[i], k);
 
          if (A[i] <= 18)
          if (sum+F[A[i]] <= M && k <= K) solve1(i+1,sum+F[A[i]],k+1);
 
     }
}
 
void solve2(int pos, long long sum, int k){
 
     for (int i = 0; i <= K-k; i++)
          if (m[i][M-sum] > 0)sol += m[i][M-sum ];
 
     for (int i = pos; i <= n; i++){
 
          if (sum+A[i] <= M) solve2 (i+1,sum+A[i], k);
 
          if (A[i] <= 18)
          if (sum+F[A[i]] <= M && k <= K) solve2(i+1,sum+F[A[i]], k+1);
 
     }
}
 
 
int main(){
 
    F[0] = 1;
    for (int i = 1; i <= 19; i++) F[i] = F[i-1]*i;
 
    cin >> n >> K >> M;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
 
    }
 
    solve1 (1,0, 0);
    solve2 ((n+1)/2+1,0, 0);
 
    /*for (int i = 1; i <= c; i++){
         if (m[M-B[i]])
             sol += (m[M-B[i]]*mm[B[i]]);
    }
*/
    cout << sol<<endl;
 
    return 0;
}