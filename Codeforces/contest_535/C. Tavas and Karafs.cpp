/*
2015-04-20 22:11:17
https://codeforces.com/contest/535/problem/C
*/
#include <iostream>
 
using namespace std;
 
long long A, B,res, n, tot, T, t, l, m, ini, fin, piv;
 
int main(){
 
    cin >> A >> B >> n;
    for (int i = 1; i <= n; i++){
         cin >> l >> t >> m;
         if (A+(l-1)*B > t) cout << "-1\n";
          else{
            tot = t*m;
            ini = l;
            fin = 1000000000;
            res = (l-1)*A+((l-2)*((l-1)))/2*B;
            while (ini+1 < fin){
                   piv = (ini+fin)/2;
                   T = piv*A+((piv-1)*(piv))/2*B-res;
                   if (T <= tot && A+(piv-1)*B <= t) ini = piv;
                   else fin = piv;
            }
            if (fin*A+((fin-1)*(fin))/2*B-res <= tot && A+(fin-1)*B <= t)
                cout << fin << endl;
             else cout << ini << endl;
          }
    }
 
    return 0;
}