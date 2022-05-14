#include <bits/stdc++.h>

using namespace std;
#define int64 long long 

int64 A[1000005], sol;
int64 S[1000005*5];

int64 update (int ini, int fin, int p, int pos, int64 v){

    if (ini > pos || fin < pos){
       
       return S[p];
   }

    if (ini == fin && fin == pos){
        
        return (S[p] = v); 
    }

    int piv = (ini+fin)/2;

    int64 a1 = update (ini, piv, p*2, pos, v);
    int64 b1 = update (piv+1, fin, p*2+1, pos, v);
    return S[p] = max(a1, b1);
   
}

int64 query (int ini, int fin, int p, int a, int b){
    
    if (ini > b || fin < a) return 0ll;

    if (a <= ini && fin <= b) return S[p];

    int piv = (ini+fin)/2;

    int64 a1 = query (ini, piv, p*2, a, b);
    int64 b1 = query (piv+1, fin, p*2+1, a, b);
    return max(a1, b1);
}


int main() {
    int n, k;
    scanf ("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
         scanf ("%lld", &A[i]);
    
    
    for (int i = 1; i < n; i++){
         update (1, n-1, 1, i, A[i+1]-A[i]);  
    }
    
    sol = 1<<31-1;
    for (int j = 0; j <= k; j++){
         int a = 1+j;
         int b = n-1-k+j;
         sol = min (sol, query(1, n-1, 1, a, b));
    }

    printf ("%lld\n", sol);
    
    return 0;
}