/*
2017-03-23 18:13:34
https://codeforces.com/contest/787/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
int a, b, c, d;
int main(){
 
     scanf ("%d%d", &a, &b);
     scanf ("%d%d", &c, &d);
     swap (a, b);
     swap (c, d);
     for (int i = 1; i <= 100000; i++){
     	  if (a == c){
     	  	  printf("%d\n", a);
     	  	  return 0;
     	  }
     	  if (a < c)a+=b;
     	  else c+=d;
     	  //printf ("%d\n", a);
     }
     
 
     printf ("-1\n");
	return 0;
}