/*
2017-10-27 19:58:53
https://codeforces.com/contest/884/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n;
long long a, tot, sol;
 
priority_queue <long long, vector <long long>, greater<long long> > Q;
//bool m[ 200000]
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 scanf ("%lld", &a);
    	 Q.push (a);
    	 tot += a;
    }
 
    if (n%2==0){
    	long long x = Q.top(); Q.pop();
        long long y = Q.top(); Q.pop();   
        Q.push (x+y);
        sol += x+y;
    }
    //printf ("%lld\n", sol);
    //int p = 1;
    while ((int)Q.size() >= 3){
           long long x = Q.top(); Q.pop();
           long long y = Q.top(); Q.pop();   
           long long z = Q.top(); Q.pop();
           Q.push (x+y+z);
           sol += x+y+z;
           //printf ("%lld %lld\n", x, y);
    }
    
    if ((int)Q.size() > 1)
    while (!Q.empty()){
    	   sol += Q.top();
    	   Q.pop();
    }
 
	printf ("%lld\n", sol);
 
	return 0;
}