#include <bits/stdc++.h>

using namespace std;
#define ll long long
int n, m, a, S[1000005], cas;

struct par{
       int v, id;
       bool operator<(const par &R)const{
            if (v != R.v)return v < R.v;
            return id < R.id;
       }
};

par A[1000005], B[1000005];
int main() {

    cin >> cas ;

    while (cas--){

            cin >> n;

          for (int i = 1; i <= n; i++){
               cin >> A[i].v;
               A[i].id = i;
          }

          for (int i = 1; i <= n; i++){
               cin >> B[i].v;
               B[i].id = i;
          }

          sort (A+1,A+n+1);
          sort (B+1,B+n+1);

          int p = n/2; bool mar = false;
          for (int i = n; i > n/2; i--){
               if (A[p].v < B[i].v){
                   S[A[p--].id] = B[i].id;
               }
               else mar = true;
          }

          p = n/2+1;
          for (int i = 1; i <= n/2; i++){
               if (A[p].v > B[i].v){
                   S[A[p++].id] = B[i].id;
               }
               else mar = true;
          }

          if (mar){
              cout << "-1\n";
              continue;
          }

          cout << S[1];
          for (int i =2; i <= n;i++) cout << " " << S[i];
          cout << "\n";
    }



    return 0;
}
