/*
2016-10-22 19:32:31
https://codeforces.com/contest/725/problem/C
*/
#include <bits/stdc++.h>
 
char A[1000000];
int dis, la, d, P[1000], p, p1;
char S[3][20];
 
int main(){
 
    scanf ("%s", A);
    int la = strlen (A);
 
    for (int i = 0; i < 28; i++) P[i] = -1;
 
    for (int i = 0; i < la; i++){
         if (P[A[i]-'A'] != -1) dis = i-P[A[i]-'A'],p1 = i;
         else P[A[i]-'A'] = i;
    }
 
    if (dis==1){
        printf ("Impossible\n");
        return 0;
    }
 
    p=dis/2;
    if (dis%2==0)p--;
    d = 1;
    int id = 0; bool mar = false;
    for (int i = P[A[p1]-'A']; i < la || !mar; i++){
 
 
         if (i == P[A[p1]-'A'] && mar) break;
 
         if (i == la && !mar){
            mar =true;
            i = -1;
            continue;
         }
 
         if (p1 == i) continue;
 
         if (d == 1 && p >= 0){
             S[id][p--] = A[i];
             continue;
         }
 
         if (d == 1 && p < 0){
             p = 0;
             S[++id][p++] = A[i];
             d = 2;
             continue;
         }
 
         if (d == 2 &&  p <= 12){
             S[id][p++] = A[i];
             continue;
         }
 
         if (d == 2 && p > 12){
             d = 3;
             p = 12;
             S[--id][p--] = A[i];
             continue;
         }
 
         S[id][p--] = A[i];
    }
 
    for (int i = 0; i < 2; i++){
         for (int j = 0; j < 13; j++)
              printf ("%c", S[i][j]);
         printf ("\n");
    }
 
    return 0;
}