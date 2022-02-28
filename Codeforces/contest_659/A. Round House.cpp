/*
2016-03-30 19:10:42
https://codeforces.com/contest/659/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int a, b, c;
int main(){
 
    cin >> a >> b >> c;
    if (c < 0){
        for (int i = 1; i <= abs(c); i++){
             b--;
             if (b == 0) b = a;
        }
    }
    else{
        for (int i = 1; i <= abs(c); i++){
             b++;
             if (b == a+1) b = 1;
        }
 
    }
 
    cout << b<<"\n";
 
    return 0;
}