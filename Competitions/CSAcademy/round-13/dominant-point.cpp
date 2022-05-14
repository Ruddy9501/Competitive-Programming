#include <cstdio>
#include <iostream>

using namespace std;

int n, X[10005], Y[10005];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++){
         cin >> X[i] >> Y[i];
    }

    for (int i = 1; i <= n; i++){
         bool mar = false;
         for (int j = 1;  j <= n; j++){
              if (j == i) continue;
              if (X[i] <= X[j] || Y[i] <= Y[j]) {
                  mar = true;
                  break;
              }
         }

         if (!mar) {
             cout << i << "\n";
             return 0;
         }
    }

    cout << "-1" << endl;
    return 0;
}
