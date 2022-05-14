/*
2015-03-27 18:06:46
https://codeforces.com/contest/525/problem/D
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
 
int f, c;
char A[2005][2005];
 
const int mx[] = {1,0,-1,0},
          my[] = {0,1,0,-1};
 
void solve (int x, int y){
 
     if (x < 2 || x > f || y < 2 ||y > c) return;
 
     int can = 0;
     for (int i = -1; i <= 0; i++)
          for (int j = -1; j <= 0; j++)
               if (A[x+i][y+j] == '*') can++;
 
     if (can == 1){
         for (int i = -1; i <= 0; i++)
              for (int j = -1; j <= 0; j++)
                   A[x+i][y+j] = '.';
 
         for (int i = -1; i <= 1; i++)
              for (int j = -1; j <= 1; j++) solve (x+i,y+j);
     }
}
 
int main(){
 
    scanf ("%d%d", &f, &c);
    for (int i = 1; i <= f; i++){
         scanf ("\n");
         for (int j = 1; j <= c; j++)
              scanf ("%c", &A[i][j]);
    }
 
    for (int i = 1; i <= f; i++)
         for (int j = 1; j <= c; j++)
              solve (i, j);
 
      for (int i = 1; i <= f; i++){
           for (int j = 1; j <= c; j++)
                printf ("%c", A[i][j]);
                printf ("\n");
      }
 
    return 0;
}