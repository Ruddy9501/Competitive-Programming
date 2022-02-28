#include <bits/stdc++.h>

using namespace std;

int A[100005], sol, may = 0;
int M[35][100005];

bool ok(int a, int b, long long num){
     a--;
     for (int i = 0; i < 31; i++){
          if (num & (1<<i) && M[i][b] - M[i][a] == 0)
              return false;
     }
     return true;
}

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]); 
         may |= A[i];
         for (int j = 0; j < 31; j++){
              if (A[i] & (1<<j))
                  M[j][i] = M[j][i-1] +1;
               else M[j][i] = M[j][i-1];
         }
    }
    
    sol = n;
    for (int i = 1; i <= n; i++){
         int ini = i, fin = min(n,i+sol-1);
         while (ini <= fin){
                int piv = (ini+fin)/2;
                if (ok(i, piv, may))
                    fin = piv-1, sol = min (sol, piv-i+1);
                 else 
                    ini = piv+1;

         }
    }

    printf ("%d\n", sol);
    
    return 0;
}
   