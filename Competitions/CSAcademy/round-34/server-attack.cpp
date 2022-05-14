#include <bits/stdc++.h>

using namespace std;

bool H[50005], S[50005];

int main() {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         int id, a;
         scanf ("%d %d", &id, &a);
         if (id == 1) H[a] = true;
          else S[a] = true;
    }
    
    int sol = 0, ult = -1;
    for (int i = 0; i <= 5000; i++){
         
         if (ult == -1 && H[i]) ult = i;
         
         if (S[i] && ult != -1){
             sol += i-ult;
             ult = -1;
         }
    }
    
    printf ("%d\n", sol);
    
    return 0;
}