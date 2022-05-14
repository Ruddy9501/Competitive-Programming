/*
2017-07-31 17:56:19
https://codeforces.com/contest/835/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long k, sum;
char s[1000005];
int S[15];
 
int main(){
    
    scanf ("%lld", &k);
    scanf ("%s", s);
    int la = strlen (s);
 
    for (int i = 0; i < la; i++){
    	 sum = sum + (s[i]-'0');
    	 S[s[i]-'0']++;
    } 
    
    int sol = 0, pos = 0;
    while (sum < k){
           sol++;
           while (S[pos] == 0) pos++;
           sum -= pos;
           S[pos]--;
           sum += 9;  
    }
    
    printf ("%d\n", sol);
 
	return 0;
}