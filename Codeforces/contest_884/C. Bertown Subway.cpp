/*
2017-10-27 19:52:03
https://codeforces.com/contest/884/problem/C
*/
#include <bits/stdc++.h>
 
 
using namespace std;
 
const int MAX = 1e5 + 5;
int n, a[MAX];
bool m[MAX];
vector <int> v;
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
         scanf ("%d", &a[i]);
    
    bool uno = true;
    for (int i = 1; i <= n; i++){
         if (m[i]) continue;
         
         int can = 0;
         int p = i;  
         while (m[p] != true){
                m[p] = true;
                p = a[p];
                can++;
         }
         if (can != 1) uno = false; 
         v.push_back (can);
    }
 
    sort (v.begin(), v.end());
    
    int l = (int)v.size();
    if (l == 1){
        long long x = v[0]; 
        printf ("%lld\n", x*x);
        return 0;
    }
 
    long long x = *v.rbegin(); v.pop_back();
    x += *v.rbegin(); v.pop_back();
    long long sol = x*x;
    while (!v.empty()){
           int x = *v.rbegin(); v.pop_back ();
           sol += x*x;
    }
 
    printf ("%lld\n", sol);
 
    return 0;
}