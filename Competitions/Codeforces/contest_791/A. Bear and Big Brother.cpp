/*
2017-03-18 18:38:17
https://codeforces.com/contest/791/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5+5;
 
int main(){
 
    int a, b;
    cin >> a >> b;
    swap (a, b);
    for (int i = 0; ; i++){
         if (a < b){
             cout << i << "\n";
             return 0;
         }
         a *= 2;
         b *= 3;
    }
 
    return 0;
}