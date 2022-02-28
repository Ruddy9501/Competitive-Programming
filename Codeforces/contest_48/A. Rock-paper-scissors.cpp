/*
2016-06-08 16:57:05	
https://codeforces.com/contest/48/problem/A
*/

#include <bits/stdc++.h>
 
using namespace std;
string a, b, c;
bool res(string a, string b){
     if (a == "rock" && b == "scissors") return true;
     if (a == "paper" && b == "rock") return true;
     if (a == "scissors" && b == "paper") return true;
     return false;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> a >> b >> c;
    char sol = '?';
    if (res(a,b) && res(a,c)) sol = 'F';
    if (res(b,a) && res(b,c)) sol = 'M';
    if (res(c,a) && res(c,b)) sol = 'S';
 
    cout << sol << endl;
 
    return 0;
}