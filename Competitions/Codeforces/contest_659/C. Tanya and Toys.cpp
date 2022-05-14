/*
2016-10-17 22:39:38
https://codeforces.com/contest/659/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
int a, b, c;
map <int, bool>M;
int s, S[10000000];
int main(){
 
    cin >> a >> b;
    for (int i = 1; i <= a; i++){
         cin >> c;
         M[c] = true;
    }
 
    for (int i = 1; ; i++){
         if (b < i) break;
         if (M[i]==true)continue;
         S[s++] = i;
         b-=i;
    }
 
    cout << s <<endl;
    if (s > 0)cout <<S[0];
    for (int i = 1; i < s; i++)
         cout << " " <<S[i];
    cout << endl;
 
    return 0;
}