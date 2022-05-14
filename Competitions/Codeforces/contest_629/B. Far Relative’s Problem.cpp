/*
2016-03-24 18:25:58
https://codeforces.com/contest/629/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, F[1000], M[1000], a, b;
char car;
int sol;
int main(){
 
    cin >> n;
    for (int i = 0; i < n; i++){
         cin >> car >> a >> b;
         b++;
         if (car=='F') F[a]++, F[b]--;
          else M[a]++, M[b]--;
    }
 
    for (int i = 1; i <= 366; i++){
         F[i] = F[i-1]+F[i];
         M[i] = M[i-1]+M[i];
 
         sol = max(sol, min(F[i],M[i])*2);
 
    }
 
    cout << sol << endl;
    return 0;
}