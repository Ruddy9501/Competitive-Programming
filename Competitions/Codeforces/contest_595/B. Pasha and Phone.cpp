/*
2015-11-08 20:32:00
https://codeforces.com/contest/595/problem/B
*/
#include <cstdio>
 
using namespace std;
 
unsigned long long n, m, sol, mul, x, y, z, A[1000000], B[1000000], M[30];
const long long MOD = 1000000007;
 
int main(){
 
    M[1] = 1ll;
    for (int i = 2; i <= 15; i++) M[i] = M[i-1]*10ll;
 
    scanf ("%I64d%I64d",&n,&m);
    for (int i = 1; i <= n/m; i++)
         scanf ("%I64d", &A[i]);
 
    for (int i = 1; i <= n/m; i++){
         scanf ("%I64d", &B[i]);
    }
 
    sol = 1;
    for (int i = 1; i <= n/m; i++){
 
         x = B[i]*M[m]-1ll;
         y = (B[i]+1ll)*M[m]-1ll;
         z = M[m+1]-1ll;
 
         mul = z/A[i]-(y/A[i]-x/A[i]);
         if (B[i]!=0) mul++;
         if (B[i]==0){
             mul = z/A[i]-((M[m]-1ll)/A[i]);
             // printf ("%I64d %I64d %I64d %I64d\n", mul, z, M[m]-1ll, A[i]);
         }
         mul = mul%MOD;
 
         sol = (mul*sol)%MOD;
    }
 
    printf ("%I64d\n", sol);
 
    return 0;
}