/*
2017-06-25 18:29:22
https://codeforces.com/contest/821/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
#define int64 long long
 
int n, id, sol, num;
char S[1000];
stack <int> P;
 
int main(){
 
    scanf ("%d", &n);
    n *= 2;
    while (n--){
           scanf ("%s %d", S, &id);
           if (S[0] == 'a') P.push(id);
            else{
               num++;
               if (P.empty()) continue;
               if (P.top() == num){
                   P.pop();
                   continue;
               }
               sol++;
               while (!P.empty()) P.pop();
            }
    }
 
    printf ("%d\n", sol);
 
    return 0;
}