/*
2015-11-18 23:18:08
https://codeforces.com/contest/592/problem/A
*/
#include <iostream>
 
using namespace std;
 
int sol1=11, sol2=11;
char A[10][10];
bool M[100], M1[100];
 
int main(){
    for (int i = 0; i < 8; i++)
         cin >> A[i];
 
    for (int i = 0; i < 8; i++){
         for (int j = 0; j < 8; j++){
              if (A[i][j]=='W'&& !M[j]) sol1 = min (sol1, i);
              if (A[i][j]=='B') M[j] = true;
 
         }
    }
 
    for (int i = 7; i >= 0; i--){
         for (int j = 0; j < 8; j++){
              if (A[i][j]=='B'&& !M1[j]) sol2 = min (sol2, 7-i);
              if (A[i][j]=='W') M1[j] = true;
 
         }
    }
 
    if (sol1 > sol2) cout << "B"<<endl;
     else cout << "A"<<endl;
 
    return 0;
}