/*
2016-09-30 17:19:25
https://codeforces.com/contest/721/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
long long n, k, a, sol, con;
char A[10000];
int  S[1000005];
int main (){
    cin >> n; char car;
    for (int i = 1; i <= n; i++){
         cin >> A[i];
    }
 
    for (int i = 1; i <= n; i++){
         if (A[i] == 'B' && A[i] != A[i-1]) sol++;
         if (A[i] == 'B'){con++;
            S[sol] = con;
         }
         else con = 0;
 
    }
 
    cout << sol << endl;
    for (int i = 1; i <= sol; i++)
         if (i == 1) cout << S[i];
          else cout << " " << S[i];
 
    cout << endl;
 
    return 0;
}