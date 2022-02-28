#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

#define RAN 6000
using namespace std;

int S[RAN][20], con;
long long n, m, dif, c, c1;
int A[20], B[20], C[20];

int main(){

    freopen ("blink.in", "r", stdin);
    freopen ("blink.out", "w", stdout);

    scanf ("%d %lld", &n, &m);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         B[i] = A[i];
         S[c][i] += A[i];
    }


    while (m){
           m--;
           c++;
           S[c][1] = S[c-1][1];
           if (S[c-1][n] == 1)
               S[c][1] = (S[c][1]+1)%2;
           for (int i = 2; i <= n; i++){
                S[c][i] = S[c-1][i];
                if (S[c-1][i-1]== 1)
                    S[c][i] = (S[c-1][i]+1)%2;
           }

           for (int i = 0; i < c; i++){
                con = 0;
                for (int j = 1; j <= n; j++){
                     if (S[c][j] == S[i][j])
                         con++;
                      else
                         break;
                }
                if (con == n){
                    dif = c-i;
                    m = (m)%dif;
                    for (int j = 1; j <= n; j++)
                         printf ("%d\n",S[m+i][j]);
                    return 0;
                }
           }

    }

    for (int j = 1; j <= n; j++)
         printf ("%d\n",S[c][j]);


    return 0;
}
