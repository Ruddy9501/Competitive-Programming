/*
https://codeforces.com/contest/1672/problem/A
2022-04-23 17:09:47
*/
#include <bits/stdc++.h>

using namespace std;

const int RAN = 2e5 + 5;
int cas, n, m, sol, x;

int main(){
    
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
           for (int i = 1; i <= n; ++i){
                scanf ("%d", &x);
                sol = sol + x - 1;
           }
           
           if (sol & 1) printf ("errorgorn\n");
           else printf ("maomao90\n");
           
           sol = 0;
           
    }

    return 0;
}
