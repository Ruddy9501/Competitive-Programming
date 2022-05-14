/*
2016-11-15 19:42:56
https://codeforces.com/contest/734/problem/A
*/
#include <iostream>
 
using namespace std;
char A[1000000];
int main(){
    int a, aa = 0, bb = 0;
    cin >> a;
    cin >> A;
    for (int i = 0; i < a; i++){
         if (A[i] == 'A') aa++;
          else bb++;
    }
 
    if (aa > bb) cout << "Anton\n";
    if (aa < bb) cout << "Danik\n";
    if (aa == bb) cout << "Friendship\n";
 
 
    return 0;
}