/*
2017-01-16 23:09:33
https://codeforces.com/contest/749/problem/C
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int n, r, d;
char A[200005], sol;
bool M[200005];
 
set <int> R, D;
set <int> ::iterator it;
 
int bus(int p, char a){
    if (a == 'D'){
        it = D.upper_bound(p);
        if (it != D.end()) return *it;
        it = D.begin();
        if (!D.empty()) return *it;
    }
    else{
        it = R.upper_bound(p);
        if (it != R.end()) return *it;
        it = R.begin();
        if (!R.empty()) return *it;
    }
    return n;
}
 
int main(){
 
    scanf ("%d", &n);
    scanf ("%s", A);
 
    for (int i = 0; i < n; i++)
         if (A[i] == 'R') R.insert(i);
          else D.insert(i);
 
    for (int i = 0; ; i++){
         i = i%n;
         if (M[i] == true) continue;
         if (A[i] == 'R'){
             d = bus(i, 'D');
             if (d >= n){
                 sol = 'R';
                 break;
             }
             M[d] = true;
             D.erase(D.find(d));
         }
         else{
             r = bus(i, 'R');
             if (r >= n){
                 sol = 'D';
                 break;
             }
             M[r] = true;
             R.erase(R.find(r));
         }
    }
 
    printf ("%c\n", sol);
 
    return 0;
}