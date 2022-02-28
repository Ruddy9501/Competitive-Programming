#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 5;
const double EPS = 0.000000001;

int n, S[MAX];
struct cua {
       int x, y, id;
       double ang;
       bool operator <(const cua &R)const{
            if (1ll*y*R.x != 1ll*R.y*x) return 1ll*y * R.x < 1ll*R.y * x;
            return x < R.x;
       }

}A[MAX];

int C[MAX];

void update (int x){
     for (int i = x; i < MAX; i += (i & -i))
          C[i]++;
}

int query (int x){
    int sol = 0;
    for (int i = x; i > 0; i -= (i & -i))
         sol += C[i];
    return sol;
}

int main(){

    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
         scanf ("%d %d", &A[i].x, &A[i].y);
         A[i].id = i;
    }



    sort (A, A+n);
   // printf ("%lf\n", fabs(A[0].ang-A[1].ang));
    for (int i = 0; i < n; i++){
         S[A[i].id] = query (A[i].x);
         update (A[i].x);
    }

    for (int i = 0; i < n; i++) printf ("%d\n", S[i]);


    return 0;
}
