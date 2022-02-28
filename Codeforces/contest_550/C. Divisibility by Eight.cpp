/*
2015-06-04 20:47:46
https://codeforces.com/contest/550/problem/C
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
 
 
using namespace std;
int sol = -1, n, la, m;
char A[1000005];
int main(){
 fill (A+0,A+1000,'0');
    scanf ("%s", A);
    la = strlen (A);
    A[la] = '0';
 
    for (int i = 0; i < la; i++){
         if (A[i] == '0'){
             printf ("YES\n0\n");return 0;
         }
    }
    la+=2;
    for (int i = 0; i < la-2; i++)
    for (int j = i+1; j < la-1; j++)
    for (int k = j+1; k < la; k++){
         if(A[i]!= '0')
             m = (A[i]-'0');
          if (j < la-2)
             m = m*10+(A[j]-'0');
          if (k < la-2)
             m = m*10+A[k]-('0');
 
         if (m%8==0){
             printf ("YES\n");
             printf ("%d\n", m);
             return 0;
         }
    }
 
    printf ("NO\n");
 
    return 0;
}