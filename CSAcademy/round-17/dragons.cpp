#include <bits/stdc++.h>

using namespace std;

int d, X[5000],c, Y[5000], c1, X1[5000], Y1[5000];

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
         for (int j = 1; j <= b; j++){
              cin >> d;
              if (d == 1){
                  X[++c] = i;
                  Y[c] = j;
              }
              else{
                  X1[++c1] = i;
                  Y1[c1] = j;
              }
         }

    int sol = 0;
    for (int i = 1; i <= c1; i++){
         int ma = 1000000;
         for (int j = 1; j <= c; j++){
              ma = min (ma, max(abs(X1[i]-X[j]), abs(Y1[i]-Y[j])));
         }
         sol = max(sol, ma);
    }


    cout << sol << "\n";
    return 0;
}
