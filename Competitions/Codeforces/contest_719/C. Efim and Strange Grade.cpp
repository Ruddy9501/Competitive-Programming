/*
2016-11-23 05:36:49
https://codeforces.com/contest/719/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2e6+5;
int n, sol, r, b;
char A[RAN];
 
 
int bus_up(int p){
    while (p > 0){
           if (A[p] == '.'){
               return -1;
           }
 
           if (A[p] >= '5') return p;
 
           p--;
    }
 
    return p;
}
 
int  aumentar(int p){
     p--;
     if (A[p] == '.') p--;
     while (A[p] == '9')
            if (A[p] == '.') p--;
             else p--;
     if (p >= 0) A[p]++;
     return p;
}
 
int main(){
 
    scanf ("%d %d", &n, &r);
    scanf ("%s", A);
    int p = n; bool mar = false;
    for (int i = 1; i < n; i++){
         if (A[i] >= '5' && mar){
             p = i;
             break;
         }
         if (A[i] == '.') mar = true;
    }
    int t = 0;
    for (int i = 0; i < n; i++, t++)
         if (A[i] == '.')break;
 
    if (p != n)
    while (r-- && p > t){
 
           int a = bus_up(p);
 
           if (a == -1) break;
           if (a == -2) break;
 
           p = aumentar(p);
           if (A[p] == '.') break;
    }
 
    if (p == -1){
        printf ("1");
        for (int i = 0; i < n; i++){
             if (A[i] == '.') break;
             printf("0");
        }
        return 0;
    }
 
    p = min(p, n-1);
    for (int i = 0; i <= p; i++){
         //if (i == p)
             printf ("%c", A[i]);
    }
 
    t = min(t, n-1);
    while (--t > p){
           printf ("0");
    }
 
    //printf ("\n");
 
   return 0;
}