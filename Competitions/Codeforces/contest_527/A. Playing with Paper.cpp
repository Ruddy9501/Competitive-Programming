/*
2015-03-27 18:23:58
https://codeforces.com/contest/527/problem/A
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
 
using namespace std;
long long a, b, sol;
int main(){
 
    cin >> a >>b;
 
 
    while (a != 0 && b != 0){
           if (b > a) swap (a, b);
           sol += a/b;
           a %= b;
    }
 
    cout << sol << endl;
 
    return 0;
}