/*
2015-03-26 19:39:51
https://codeforces.com/contest/525/problem/A
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
 
int n, sol, C[1000];
char car, dor;
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i < n; i++){
         cin >> car >> dor;
         car -= 'a';
         C[car]++;
         dor -= 'A';
         if (C[dor] > 0){
             C[dor]--;
             continue;
         }
         sol++;
    }
 
    cout << sol << endl;
 
    return 0;
}