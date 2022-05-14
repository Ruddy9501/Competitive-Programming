# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

long long t, sol=1;
long long C[2000];
long long F[350];
char A[350], B[350];

void bus_fac (){
     F[0] = 1;
     for (int i = 1; i <= 20; i++)
          F[i] = F[i-1] * i;
}

int per (int p){
    long long f1 = 1, ff = t-p, fm=0, fi;
    fill (C + 1, C + 160, 0);
    for (int i = p+1; i <= t; i++){
        C[B[i]]++;
        if(fm < C[B[i]]){
            fm = C[B[i]];
            fi = B[i];
        }
    }
    C[fi] = 0;
    for (int i = fm+1; i <= ff; i++)
         f1 *= i;
    for (int i = 0; i <= 130; i++)f1 /=(long long) F[C[i]];
    return f1;
}

void bus_sig(char x, int p){
     for (int i = p+1; i <= t; i++)
          if (B[i] > x){
              swap (B[i], B[p]);
              return ;
          }
}

int main (){

    freopen ("permu.in", "r", stdin);
    freopen ("permu.out", "w", stdout);

    scanf ("%s", A + 1);
    strcpy (B + 1 , A + 1);
    t = strlen (B + 1);
    sort (B + 1, B + t + 1);

    bus_fac();

    for (int i = 1; i <= t; i++){
         while (A[i] != B[i]){
                sol += per (i);
                bus_sig (B[i], i);
                sort(B+i+1, B+t+1);
         }
    }

    printf ("%lld", sol);
    return 0;
}
