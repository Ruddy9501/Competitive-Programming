#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
int n, la, sum;
char a[MAX];

int main(){
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
         scanf ("%s", a);
         la = strlen (a);
         
         sum = 0;
         for (int j = 0; j < la; ++j)
              sum += (a[j] - '0');
        
        
         int res = (9 - sum % 9) % 9;
         printf ("Case #%d: ", i);
         bool flag = 0;
         if (res == 0) printf ("%c", a[0]);
         for (int j = 0 + (res == 0); j < la; ++j){
              if (a[j]-'0' > res && flag == 0){
                  printf("%d", res);
                  flag = 1;
              }
              printf ("%c", a[j]);
         }
         if (!flag) printf ("%d", res);
         printf ("\n");
    }
    
    return 0;
}
