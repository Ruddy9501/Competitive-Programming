/*
https://codeforces.com/contest/1660/problem/C
2022-03-31 18:05:21
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e5 + 5;
int n, cas, b[30], s[RAN];
char a[RAN];
 
 
int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        
           scanf ("%s", a + 1);
           int la = strlen (a + 1);
           s[1] = 1;
           fill (b, b+30, -1);
           b[a[1] - 'a'] = 1;
           for (int i = 2; i <= la; ++i){
                int p = a[i] - 'a';
                s[i] =s[i - 1] + 1;
                if (b[p] != -1)
                    s[i] = min (s[i], s[b[p] - 1] + i - b[p] - 1);
                b[p] = i;
               // printf ("%d ", s[i]);
           }
           
           printf ("%d\n", s[la]);
    }
    
 
    return 0;
}