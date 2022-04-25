/*
https://codeforces.com/contest/1669/problem/D
2022-04-22 13:32:27
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 2e5 + 5;
int n, m;
char a[RAN];
 
bool f(char x){
    
    return (x=='W'||x=='\n');
}
 
int main(){
    
    scanf ("%d", &n);
    while (n--){
           scanf ("%d", &m);
           scanf ("%s", a + 1);
           a[m+1] = 'W';
           bool flag = true;
           int ant = 0;
           for (int i = 1; i <= m+1; ++i){
               if (a[i] == 'W'){
                
                int b=0, r=0;
                for (int j = ant+1; j < i; ++j){
                     if (a[j] == 'B') b = 1;
                     if (a[j] == 'R') r = 1;
                }
                
                //printf ("%d %d %d\n", i, r, b);
                if (r+b == 1) flag = false;
                
                ant = i;
               }
               else{
                   if (f(a[i-1]) && f(a[i+1])) flag = false;
               }
           }
           
           if (flag) printf ("YES\n");
           else printf("NO\n");
    }
    
    return 0;
}
