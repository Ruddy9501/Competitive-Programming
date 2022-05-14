#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
int s[10005];

int main(){
	
	int64 n, c, t;
	scanf ("%lld%lld%lld", &t, &c, &n);
	for (int i = 0; i < n; i++){
		 int64 x,y,v;
	     scanf ("%lld %lld %lld", &x, &y, &v);
	     long long a = v/(__gcd(v, c)) * c;
	     //printf ("%lld\n", a);
	     for (int j = 0; j < t; j++){
			  int64 a1 = j*a + x*a/c;
		      int64 a2 = y*a/v;
		 	  if (a1 == a2) s[j]++; 
		 	  //printf ("%d %lld %lld\n", j, a1, a2);
		 }//printf ("-----------------\n");
	}
	
	for (int i = 0; i < t; i++) printf ("%d\n", s[i]);
	
    return 0;	
}
