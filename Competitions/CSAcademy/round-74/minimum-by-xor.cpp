#include <iostream>

using namespace std;

int main() {
    
    int n;scanf ( "%d", &n);
    printf ("%d\n", (1<<n)-1);
    for (int i = 1; i < 1<<n; i++){
         int r = __builtin_popcount (i);
         printf ("%d", r);
         for (int j = 0; j < n; j++)
              if (i & (1<<j))
                  printf (" %d", j+1);
         printf ("\n");              
    }
    
    return 0;
}