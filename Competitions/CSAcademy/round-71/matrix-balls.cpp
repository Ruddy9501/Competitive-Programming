#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;
int n, m, k, ii[MAX][MAX], id[MAX], r[MAX][MAX], a[MAX][MAX];
struct tres{
       int x, y, v;
       bool operator <(const tres &r)const{
       	    return v > r.v;
       }
};

vector <tres> v;

const int mx[] = {0, 0, 1,-1, 1, 1, -1, -1},
          my[] = {1,-1, 0, 0, 1, -1, 1, -1}; 



int main(){

    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){ 
         for (int j = 1; j <= m; j++){
         	  scanf ("%d", &a[i][j]);
         	  r[i][j] = 1; 
         	  v.push_back ({i, j, a[i][j]});
         }
    }

    sort (v.begin(), v.end());
    for (auto u : v){
    	 int mi = u.v, x_ = u.x, y_ = u.y;
         for (int i = 0; i < 8; i++){
              int nx = u.x + mx[i];
              int ny = u.y + my[i];
         	  if (nx < 1 || ny < 1 || nx > n || ny > m) continue; 
         	  if (a[nx][ny] < mi){
         	  	  mi = a[nx][ny];
         	  	  x_ = nx;
         	  	  y_ = ny;
         	  }
         }  

        
         if (x_ == u.x && y_ == u.y) continue;
         	
         	 r[x_][y_] += r[u.x][u.y];
         	 r[u.x][u.y] = 0;
        
    }

    for (int i = 1; i <= n; i++){
    	 for (int j = 1; j <= m; j++){
    	 	  printf ("%d", r[i][j]);
    	 	  if (j < m) printf (" ");
    	 	   else printf ("\n");
    	 }
    }

	return 0;
}