#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 55;
int cas, n, m;
char a[RAN][RAN];
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        scanf ("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
             scanf ("%s", a[i]);
             
        
        for (int i = n-1; i >= 0; --i){
             for (int j = 0; j < m; ++j){
                  if (a[i][j] == '*'){
                      int p = i;
                      for (int k = i+1; k < n; ++k){
                           if (a[k][j] == 'o' || a[k][j] == '*') break;
                           if (a[k][j] == '.') p = k;
                      }
                      
                      a[i][j] = '.';
                      a[p][j] = '*';
                  }
             }
        }
        
        for (int i = 0; i < n; ++i){
             for (int j = 0; j < m; ++j) printf ("%c", a[i][j]);
             printf ("\n");
        }
    }
    
    return 0;
}
