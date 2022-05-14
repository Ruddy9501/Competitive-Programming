/*
2015-11-13 18:57:00
https://codeforces.com/contest/598/problem/B
*/
#include <iostream>
#include <string>
#include <cstring>
 
using namespace std;
int la, ini, fin, Q, T;
char A[100000], B[100000], tem, tem1;
int main(){
 
    cin >> A+1;
    la = strlen (A+1);
    cin >> Q;
    while (Q--){
           cin >> ini >> fin >> T;
           T = T%(fin-ini+1);
           if (T==-1)continue;
           for (int i = 1; i <= la; i++) B[i] = A[i];
           for (int i = ini; i <= fin; i++){
                if (ini+T > fin) T = 0;
                B[ini+T] = A[i];
                T++;
           }
           for (int i = 1; i <= la; i++) A[i] = B[i];
    }
 
    cout << A+1<<endl;
 
    return 0;
}