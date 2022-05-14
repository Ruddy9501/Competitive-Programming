/*
2016-04-20 21:39:33
https://codeforces.com/contest/665/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
int la;
char A[1000000];
 
char bus(int i){
     for (int j = 'a'; j <= 'z'; j++)
          if (j != A[i] && j != A[i-1] && j != A[i+1])
              return j;
}
 
int main(){
 
 
    cin >> A;
    la = strlen (A);
    for (int i = 1; i < la; i++)
         if (A[i] == A[i-1])
             A[i] = bus(i);
 
    cout << A<<endl;
 
    return 0;
}