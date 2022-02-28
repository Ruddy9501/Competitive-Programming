#include <bits/stdc++.h>

using namespace std;

int n;
string A[100];
vector <int> s;

int main(){

    cin >> n;
    for (int i = 0; i < n; i++)
         cin >> A[i];

    for (int i = 0; i < n; i++){
         bool ok = true;
         for (int j = 0; j < n && ok; j++){
              for (int k = j + 1; k < n; k++){
                   string s1 = A[j] + A[k];
                   string s2 = A[k] + A[j];
                   if (A[i] == s1 || A[i] == s2){
                       s.push_back(i+1);
                       ok = false;
                       break;
                   }
              }
         }
    }

    for (int i = 0; i < s.size(); i++){
         cout << s[i];
         if (i == s.size()-1) cout << "\n";
         else cout << " ";
    }

    return 0;
}
