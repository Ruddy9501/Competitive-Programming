/*
2017-11-20 17:23:41
https://codeforces.com/contest/894/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int sol;
char a[1005];
 
int main(){
    
    scanf ("%s", a);
    int l = strlen (a);
    for (int i = 0; i < l; i++)
        for (int j = i+1; j < l; j++)
             for (int k = j+1; k < l; k++)
                  if (a[i] == 'Q' && a[j] == 'A' && a[k] == 'Q') sol++;
    
    printf ("%d\n", sol);               
    
    return 0;
}
