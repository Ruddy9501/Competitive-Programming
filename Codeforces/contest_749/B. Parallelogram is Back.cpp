/*
2017-01-16 22:41:21
https://codeforces.com/contest/749/problem/B
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int x1, x2, x3,y,y2,y3;
int main(){
 
    scanf ("%d%d",&x1,&y);
    scanf ("%d%d",&x2,&y2);
    scanf ("%d%d",&x3,&y3);
 
    printf ("3\n");
    printf ("%d %d\n", x1-x2 + x3-x2 + x2, y-y2 + y3-y2 + y2);
    printf ("%d %d\n", x2-x1 + x3-x1 + x1, y2-y + y3-y + y);
    printf ("%d %d\n", x2-x3 + x1-x3 + x3, y2-y3 + y-y3 + y3);
 
    return 0;
}