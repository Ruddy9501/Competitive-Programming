/*
https://codeforces.com/contest/1660/problem/D
2022-03-31 19:05:03
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e5 + 5;
int n, cas, a[RAN], nn[RAN], nd[RAN], sol, ini, fin;
 
 
void solve (int x, int y){
    //printf ("%d %d\n", x, y);
 
    int nn_ = nn[y] - nn[x-1];
    int nd_ = nd[y] - nd[x-1];
    
    if (nn_%2 == 0){
        if (nd_ > sol){
            sol = nd_;
            ini = x-1;
            fin = n-y;
        }
        
        return ;
    }
    //printf ("%d\n", nn_);
    for (int j = x; j <= y; j++){
         if (a[j] < 0){
             nd_ = nd[y] - nd[j];
          //   printf ("--- %d %d\n", nd_, j);
             if (nd_ > sol){
                sol = nd_;
                ini = j;
                fin = n-y;
                
              // printf ("%d %d %d\n", ini, fin, sol);
               
             }
             break;
         }
    }
    
    for (int j = y; j >= x; j--){
         if (a[j] < 0){
             nd_ = nd[j-1] - nd[x-1];
             //printf ("+++ %d %d\n", nd_, j);
             if (nd_ > sol){
                sol = nd_;
                ini = x-1;
                fin = n-j+1;
              //  printf ("%d %d %d\n", ini, fin, sol);
             }
             break;
         }
    }
    
}
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        
           scanf ("%d", &n);
           fill (nd, nd+n+1, 0);
           fill (nn, nn+n+1, 0);
            for (int i = 1; i<= n; ++i){
                scanf ("%d", &a[i]);
                nd[i] = nd[i-1];
                nn[i] = nn[i-1];
                if (abs(a[i]) == 2) nd[i]++;
                if (a[i] < 0) nn[i]++;
            }
           
           sol = 0;
           int p = 1;
           ini = n;
           fin = 0;
           for (int i = 1; i <= n; ++i){
               if (a[i] == 0 || i == n){
                   solve (p, i-(a[i]==0));
                   p = i+1;
               }
           }
           
           printf ("%d %d\n", ini, fin);
    }
    
 
    return 0;
}