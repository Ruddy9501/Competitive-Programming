/*
https://codeforces.com/contest/1672/submission/154710510
2022-04-23 17:23:45
*/
#include <bits/stdc++.h>

using namespace std;

const int RAN = 2e5 + 5;
int cas;
char a[RAN];

int main(){
    
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%s", a);
           int l = strlen (a);
           
           if (l == 1 || a[0] == 'B' || a[l-1] != 'B'){
               printf ("NO\n");
               continue;
           }
           
           a[l] = 'A';
           
           bool sol = true;
           int aa = 0, bb = 0;
           for (int i = 0; i <= l; ++i){
                if (a[i] == 'B') bb++;
                if (a[i] == 'A') aa++;
                 if (aa < bb){
                     sol = false;
                     break;
                }
           }
           
           if (sol) printf ("YES\n");
           else printf ("NO\n");
           
    }

    return 0;
}
