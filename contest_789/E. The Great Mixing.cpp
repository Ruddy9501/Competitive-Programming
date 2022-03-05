/*
2017-03-31 19:59:06
https://codeforces.com/contest/789/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2e3 + 5;
const int MAX = 2e3;
 
int n, k, a, M[RAN];
int amax = 0, amin = 2e3;
queue <int> Q;
vector <int> v;
 
int main(){
 
    scanf ("%d %d", &k, &n);
    for (int i = 0; i < n; i++){
         scanf ("%d", &a);
         M[a] = 1;
         amin = min (amin, a);
         amax = max (amax, a);
    }
 
    for (int i = 0; i <= MAX; i++)
         if (M[i]){
             Q.push(i);
             v.push_back(i-k);
         }
    //cout << amin << " " << amax;
    while (!Q.empty()){
           a = Q.front(); Q.pop();
           for (int i = 0; i < v.size(); i++){
                int b = v[i];
                if (a+b >= amin && a+b <= amax && M[a+b] == 0){
                    M[a+b] = M[a] + 1;
                    Q.push(a+b);
                    //v.push_back(a+b);
                }
           }
    }
 
    if (M[k]) printf ("%d\n", M[k]);
     else printf ("-1\n");
 
    return 0;
}