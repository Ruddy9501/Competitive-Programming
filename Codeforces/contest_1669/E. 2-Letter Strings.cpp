/*
https://codeforces.com/contest/1669/problem/E
2022-04-23 15:37:47
*/
#include <bits/stdc++.h>

using namespace std;
const int RAN = 2e5 + 5;
int cas, n, c1[30], c2[30], c3[30][30];
long long sol;
char a[5];

int main(){
    
    scanf ("%d", &cas);
    while (cas--){
        scanf ("%d", &n);
        for (int i = 1; i <= n; ++i){
             scanf ("%s", a);
             
             sol += c1[a[0]-'a'] + c2[a[1] - 'a'] - 2ll * c3[a[0] - 'a'][a[1] - 'a'];
             
             c1[a[0] - 'a']++;
             c2[a[1] - 'a']++;
             c3[a[0] - 'a'][a[1] - 'a']++;
        }
        
        printf ("%lld\n", sol);
        sol = 0;
        
        memset (c1, 0, sizeof(c1));
        memset (c2, 0, sizeof(c2));
        memset (c3, 0, sizeof(c3));
    }
    
    return 0;
}
