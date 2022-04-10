#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
char a[MAX], b[MAX], sol;

int main(){
    
    int n;scanf ("%d", &n);
    for (int i = 1; i <= n; ++i){
         scanf ("%s %s", &a, &b);
         int la = strlen(a);
         int lb = strlen(b);
         
         int p = 0;
         for (int j = 0; j < lb; ++j)
              if (a[p] == b[j]) p++;
              
         if (p >= la) printf ("Case #%d: %d\n", i, lb-la);
         else printf ("Case #%d: IMPOSSIBLE\n", i);
    }
    
    return 0;
}
