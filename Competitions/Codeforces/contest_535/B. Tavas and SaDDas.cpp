/*
2015-04-20 21:01:40
https://codeforces.com/contest/535/problem/B
*/
#include <iostream>
#include <cstring>
 
using namespace std;
 
char n[20];
long long sol, l, mul;
 
int main(){
 
    cin >> n;
    l = strlen (n);sol = 0;
    mul = 1;
    for (int i = l-1; i >= 0; i--){
         if (n[i]=='4') sol += mul;
         else sol += mul*2;
         mul *= 2;
    }
 
 
    cout << sol << endl;
 
    return 0;
}