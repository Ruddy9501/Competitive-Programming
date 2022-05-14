/*
2017-07-11 20:09:03
https://codeforces.com/contest/828/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, b, A[105][105];
char car;
 
int main(){
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
         for (int j = 1; j <= m; j++){
         	  cin >> car;
         	  A[i][j] = A[i][j-1] + A[i-1][j] - A[i-1][j-1];
         	  if (car == 'B') A[i][j] ++, b++;
         } 
    
    int sol = 100*100*105;
    for (int i = 1; i <= n; i++){
    	 for (int j = 1; j <= m; j++){
              for (int l = 0; i+l <= n && j+l <= m; l++){
              	   int t = A[i+l][j+l] - A[i-1][j+l] - A[i+l][j-1] + A[i-1][j-1];
              	   if (t != b) continue;
                   sol = min (sol, (l+1)*(l+1) - t);
              } 
 
    	 }
    }
     
    if (sol != 100*100*105)cout << sol << "\n";
     else cout << "-1\n";
	return 0;
}