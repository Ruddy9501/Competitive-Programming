/*
https://codeforces.com/contest/1661/problem/B
2022-04-09 18:03:58
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5 + 5;
 
int cas, n;
long long a[MAX], b[MAX], dp[MAX][2];
 
int main(){
 
    scanf ("%d", &cas);
    while (cas--){
           scanf ("%d", &n);
 
           if (n == 0){
               printf ("0\n");
               continue;
           }
 
           int sol = 100;
 
 
           for (int i = 0; i <= 20; ++i){
 
                int sol1 = i;
                int n1 = n + i;
                int con = 0;
 
               if (n1%2 == 1) n1++, sol1++;
 
               while (n1 % 2 == 0){
                      con++;
                      n1 /= 2;
               }
 
               if (con < 15) sol1 += (15-con);
 
               sol = min (sol, sol1);
           }
 
           printf ("%d ", sol);
    }
 
 
    return 0;
}