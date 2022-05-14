/*
2017-02-03 17:25:26
https://codeforces.com/contest/764/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
 
int n, m, q, a, b, x, y, A[RAN], B[RAN];
bool M[RAN], M1[RAN];
priority_queue <int> Q;
 
int div(int a){
    if (a%2==0) return 2;
    for (int i = 3; i*i <= a; i+=2)
         if (a%i==0) return i;
    return a;
}
 
int solve(){
    int sol = 0;
    fill (M+1, M+RAN, false);
    int it1, it2;
    while (Q.size() >= 1){
           it1 = Q.top(); Q.pop();
           it2 = Q.top();
           if (it1 == it2){
               if (!M[it1]) sol++;
               M[it1] = true;
           }
           else{
              int b = div(it1);
              if (M1[b])sol++;
              b = it1/b;
              Q.push(b);
           }
    }
 
    while (!Q.empty()) Q.pop();
 
    return sol;
}
 
int main(){
    
   scanf ("%d", &n);
   printf ("YES\n");
   while (n--){
          scanf ("%d %d %d %d", &x, &y, &a, &b);
          if (x < a) swap(x, a), swap(y, b);
          x = abs(x);
          y = abs(y);
          if (x%2==1 && y%2==1) printf ("1\n");
          if (x%2==0 && y%2==0) printf ("2\n");
          if (x%2==1 && y%2==0) printf ("3\n");
          if (x%2==0 && y%2==1) printf ("4\n");
   }
    return 0;
}