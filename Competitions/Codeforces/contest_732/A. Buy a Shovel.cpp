/*
2016-10-17 17:55:34
https://codeforces.com/contest/732/problem/A
*/
 # include <bits/stdc++.h>
 using namespace std;
int k, r;
 int main(){
 
     cin >> k >> r;
 
     for (int i = 1; ; i++){
          if ((k*i)%10 == r || (k*i)%10 == 0){
              cout << i << endl;
              return 0;
          }
     }
 
     return 0;
 }