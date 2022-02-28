/*
2016-06-24 16:59:49
https://codeforces.com/contest/686/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
 
long long n, A[1005], mi;
 
long long bus_min(int i){
      long long m = 1e9 +7;
      for ( ; i <= n; i++)
           m = min (m, A[i]);
      return m;
}
 
void are(int p, int m){
     int i = p;
     for ( ; A[i] != m; i++);
     for ( ; i != p; i--){
          cout << i-1 << " " << i << endl;
          swap (A[i], A[i-1]);
     }
}
 
int main (){
 
    cin >> n;
    for (int i = 1;i <= n; i++)
         cin >> A[i];
 
    for (int i = 1; i <= n; i++){
         mi = bus_min(i);
         if (A[i] == mi) continue;
         are(i, mi);
    }
 
	return 0;
}