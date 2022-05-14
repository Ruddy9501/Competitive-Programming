#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int n;
int64 a, b, sol = 1ll<<60;

struct par{
	   int64 a, b;
	   bool operator <(const par &r)const{
	        return a < r.a; 
	   }
}; 

vector <par> v;

int main(){
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
	     scanf ("%lld %lld", &a, &b);
	     v.push_back ({a, b});
	}
	
	sort (v.begin(), v.end());
	
	int l = (int)v.size();
	for (int i = 0; i < l; i++){
	     int64 c1 = 0, c2 = 0, a = v[i].a, b = v[i].b;
	     for (int j = i-1; j >= 0; j--){
		      c1 += abs (a-v[j].b);
		      a = v[j].a + abs (a-v[j].b);
		      //printf ("%lld ", a);
		 } //printf ("\n");
		 
		 for (int j = i+1; j < l; j++){
		      c2 += abs (v[j].a-b);
		      b = v[j].b - abs (v[j].a-b);
		     // printf ("%lld ", b);
		 }//printf ("\n");
		 
		 //printf ("%lld %lld %lld\n-------------\n", v[i].a, v[i].b, c1+c2);
		 
		 sol = min (sol, c1 + c2);
	}
	
	printf ("%lld\n", sol);
	
    return 0;
}
