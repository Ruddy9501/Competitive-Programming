/*
2016-10-03 14:50:54
https://codeforces.com/contest/723/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
int n;
char A[1000];
 
bool is_letra(int p){
     if (A[p] >= 'A' && A[p] <= 'Z') return true;
     if (A[p] >= 'a' && A[p] <= 'z') return true;
     return false;
}
int l, p, sol1, sol2;
int main(){
 
    cin >> n;
    cin >> A;
    for (int i = 0; i < n; i++){
 
         if (is_letra(i)) l++;
          else{
             if (p == 0)
                sol1 = max(sol1, l);
              else
                if (l > 0)
                    sol2++;
             l = 0;
          }
         if (A[i] == '(')p++;
         if (A[i] == ')')p--;
    }
 
    if (l > 0) sol1 =max(sol1, l);
 
    cout << sol1 << " " <<sol2;
    return 0;
}