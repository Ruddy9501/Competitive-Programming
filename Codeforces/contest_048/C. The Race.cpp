/*
2016-06-09 03:23:32
https://codeforces.com/contest/48/problem/C
*/

#include <bits/stdc++.h>
 
using namespace std;
 
 
int n;
double A[1005],ini, fin, mi,ma, piv;
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
 
    mi = 0;
    ma = 1<<29;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
         mi = max (mi,  (double)(A[i]/(double)i));
         ma = min (ma,  (double)((A[i]+1.0)/(double)i));
    }
 
    mi += 1e-10;
    ma -= 1e-10;
 
    double p1 = 0;
    double p2 = 0;
    for (int i = 1; i <= n+1; i++){
         p1 += mi;
         p2 += ma;
    }
 
    int r1 = p1;
    int r2 = p2;
 
    if (r1 == r2){
        cout << "unique" << endl;
        cout << r1 << endl;
    }
     else{
        cout << "not unique" << endl;
     }
 
    return 0;
}