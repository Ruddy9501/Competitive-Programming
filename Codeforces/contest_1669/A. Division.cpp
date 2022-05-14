/*
https://codeforces.com/contest/1669/problem/A
2022-04-22 12:59:49
*/
#include <bits/stdc++.h>

using namespace std;

const int RAN = 2e5 + 5;
int n, m;

int f(int x){
    if (m <= 1399) return 4;
    if (m <= 1599) return 3;
    if (m <= 1899) return 2;
    return 1;
    
}

int main(){
    
    scanf ("%d", &n);
    while (n--){
           scanf ("%d", &m);
           printf ("Division %d\n", f(m));
    }
    
    return 0;
}
