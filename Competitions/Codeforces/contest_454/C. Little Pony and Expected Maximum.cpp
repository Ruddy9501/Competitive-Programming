/*
2018-03-17 04:26:23
https://codeforces.com/contest/454/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef double int64;
double sol = 0;
int x, y;
 
int64 exp(int64 a, int n) {
    int64 ans = 1;
    while(n > 0) {
        if(n % 2LL == 1LL)
            ans = ans * a;
            
        a = a * a;
        n /= 2LL;
    }
    
    return ans;
} 
 
int main(){
 
    scanf ("%d%d", &x, &y);
    for (int i = 1; i <= x; i++){
    	 double s2 = exp (1.0 * (i-1)/x, y);
    	 double s1 = exp (1.0 * i/x, y);
         sol += 1.0 * i * (s1-s2);
    }
 
    printf ("%.10lf\n", sol);
 
	return 0;
}