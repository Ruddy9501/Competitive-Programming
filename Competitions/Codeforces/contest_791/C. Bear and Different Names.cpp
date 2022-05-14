/*
2017-03-18 19:19:53
https://codeforces.com/contest/791/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e6+5;
int c, can, n, k;
string Name[100], S[100], a;
 
int main(){
 
  for (int i = 0; i < 26; i++) Name[c++] = char('A' + i);
  for (int i = 0; i < 26; i++) Name[c++] = Name[c-26] + char('a'+i);
 
  cin >> n >> k;
 
  cin >> a;
  if (a == "NO"){
      S[1] = S[2] = Name[can++];
      for (int i = 3; i <= k; i++)
           S[i] = Name[can++];
  }
  else{
     for (int i = 1; i <= k; i++)
          S[i] = Name[can++];
  }
 
  for (int i = k+1; i <= n; i++){
       cin >> a;
       if (a == "YES") S[i] = Name[can++];
        else S[i] = S[i-k+1];
  }
 
  for (int i = 1; i <= n; i++){
       if (i == n) cout << S[i] << "\n";
        else cout << S[i] << " ";
  }
 
  return 0;
}