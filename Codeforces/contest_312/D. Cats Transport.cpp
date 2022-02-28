/*
2016-04-05 17:18:41
https://codeforces.com/contest/316/problem/A2
*/

#include <bits/stdc++.h>
 
using namespace std;
int n, con;
long long can, mul=1;
long long M[1000];
char A[100005];
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
 
    cin >> A;
    int la = strlen (A);
    if (A[0]=='?')mul = 9;
    for (int i = 1; i < la; i++){
         if (A[i]=='?')con++;
    }
 
   can = 10;
   if (A[0] >= 'A'&& A[0] <= 'J'){
       M[A[0]] = can;
       mul *= 9ll;can--;
   }
 
       for (int i = 1; i < la; i++){
             if (A[i] >= 'A'&& A[i] <= 'J'){
                 if (!M[A[i]]) {
                    mul *= can;
                    M[A[i]] = can;
                    can--;
                 }
             }
    }
 
    cout << mul;
    for (int i =1;i<=con;i++)cout<<"0";
    cout<<"\n";
 
    return 0;
}