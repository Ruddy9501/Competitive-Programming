/*
2015-09-16 18:24:51
https://codeforces.com/contest/579/problem/A
*/
#include <cstdio>
 
using namespace std;
 
long long n;
int sol;
 
int main(){
 
    scanf ("%I64d", &n);
 
    sol = 1;
    while (n > 1){
           if (n%2==1)sol++;
           n=n/2;
    }
 
    printf ("%d\n", sol);
 
    return 0;
}