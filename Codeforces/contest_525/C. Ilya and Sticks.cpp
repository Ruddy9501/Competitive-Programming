/*
2015-03-26 20:08:19
https://codeforces.com/contest/525/problem/C
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n;
long long last, sol, A[1000000];
bool mar;
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1;  i <= n; i++)
         cin >> A[i];
 
    sort (A+1,A+n+1);
 
    for (int i = n; i > 1; ){
         if (A[i] == A[i-1]) {
             if (mar==true){
                 mar = false;
                 sol += (last* A[i]);
             }
             else{
                 mar = true;
                 last = A[i];
             }
             i-=2;
             continue;
         }
         if (A[i]-1 == A[i-1]){
             if (mar==true){
                 mar = false;
                 sol += (last*A[i-1]);
             }
             else{
                 mar = true;
                 last = A[i-1];
             }
             i-=2;
             continue;
         }
         i--;
    }
 
 
    cout << sol << endl;
 
    return 0;
}