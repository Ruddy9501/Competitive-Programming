/*
2017-02-02 16:45:16
https://codeforces.com/contest/764/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, A[1000000];
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    int ini =1, fin = n, con = 0;
    while (ini <= fin){
           con++;
           if (con%2) swap(A[ini], A[fin]);
           ini++;
           fin--;
    }
 
    cout << A[1];
    for (int i = 2; i <= n; i++)
         cout << " " << A[i];
    cout << "\n";
 
    return 0;
}