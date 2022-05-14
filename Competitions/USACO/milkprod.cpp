/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007-2008/noviembre/plata
Tiempo Lechero/milkprod
DINAMICA
*/
#include <cstdio>
#include <algorithm>

using namespace std;

struct tres{
       int i, f, c;
       tres(int a = 0, int b = 0, int d = 0){
            i = a;
            f = b;
            c = d;
       }
       bool operator <(const tres &R)
       const{
             return R.f > f;      
       }     
}A[100000];

int n, m, r, pos, c, S[1000005];

int main (){
    
    freopen ("milkprod.in", "r", stdin);
    freopen ("milkprod.out", "w", stdout);
    
    scanf ("%d %d %d\n", &n, &m, &r);
    for (int i = 1; i <= m; i++)
         scanf ("%d %d %d\n", &A[i].i, &A[i].f, &A[i].c);
    
    sort (A + 1, A + m + 1);
    
    c = 1;
    for (int i = 1; i <= n; i++){
         S[i] = max(S[i-1], S[i]);
         if (A[c].f == i){ 
             pos = 0;       
             if (A[c].i-r > 0)
                 pos = A[c].i-r;          
             if (S[pos] + A[c].c > S[i])
                 S[i] = S[pos] + A[c].c; 
             c++; 
             i--;      
         }  
    }
    
    printf ("%d\n", S[n]);
    return 0;      
}
