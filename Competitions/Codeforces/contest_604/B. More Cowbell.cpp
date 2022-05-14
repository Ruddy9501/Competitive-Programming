/*
2015-12-01 20:19:00
https://codeforces.com/contest/604/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, a, m, sol, A[1000005];
priority_queue <int,vector<int>, greater<int> >Q;
 
int main(){
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
         sol = max (A[i], sol);
    }
    int can = n;
    int ini = 1, fin = ((n)-m)*2;
    while (m < can){
         sol = max (sol, A[ini]+A[fin]);
         ini++;fin--;
         can-=2;
         m--;
    }
 
   cout << sol << endl;
    return 0;
}