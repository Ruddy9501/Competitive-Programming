/*
2016-04-05 17:28:27
https://codeforces.com/contest/478/problem/C
*/
# include <bits/stdc++.h>
 using namespace std;
 
 long long a[5], sol;
 
 int main(){
    scanf("%I64d %I64d %I64d", &a[0], &a[1], &a[2]);
    sort(a, a+3);
    sol = (a[0]+a[1]+a[2])/3ll;
 
 
    if(sol*3-min(a[2],2*sol) > a[1]+a[0])sol = a[1]+a[0];
 
    printf("%I64d\n", sol);
 }