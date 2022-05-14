/*
2022-03-10 17:39:30
https://codeforces.com/contest/1651/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
 
multiset <long long> s;
int cas, n;
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
            scanf ("%d", &n);
           printf ("%d\n", (1<<n) - 1);
    }
 
    return 0;
}