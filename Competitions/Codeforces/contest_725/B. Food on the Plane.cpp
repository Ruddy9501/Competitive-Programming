/*
2016-10-22 18:26:17
https://codeforces.com/contest/725/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
long long n, sol, pot = 1;;
char A[1000000];
 
long long ar(char a){
     if (a == 'f') return 1ll;
     if (a == 'e') return 2ll;
     if (a == 'd') return 3ll;
     if (a == 'a') return 4ll;
     if (a == 'b') return 5ll;
     return 6ll;
}
 
int main(){
 
    scanf ("%s", A);
    int la = strlen (A);
 
    for (int i = la-2; i >= 0; i--){
         n += ((A[i]-'0')*pot);
         pot*=10ll;
    }
 
    if (n%4ll!=0)sol = n/4ll*16ll;
     else sol = (n-1ll)/4ll*16ll;
    n %= 2ll;
 
    if (n == 0) sol += 7;
 
    sol += ar(A[la-1]);
 
    printf ("%I64d\n", sol);
 
    return 0;
}