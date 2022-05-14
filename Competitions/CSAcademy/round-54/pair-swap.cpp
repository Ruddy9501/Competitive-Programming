#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5; 
int n, k;
int a[MAX];

struct par{
       int v, p;
       bool operator <(const par &r)const{
       	    if (v != r.v) return v < r.v;
            return p > r.p;
       }
};

multiset <par> s;
 
int main(){
    
    scanf ("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
    	 scanf ("%d", &a[i]);
         if (i < k)
         	 s.insert ((par){a[i], i});
    }

    for (int i = 0; i < n-1; i++){
    	 s.erase ((par){a[i], i});
    	 if (i+k < n)
    	 	 s.insert ((par){a[i+k], i+k});
    	 auto p = s.begin();	
    	 if (p -> v < a[i]){
             swap (a[i], a[p -> p] );
             break;
    	 }    	
    }

    for (int i = 0; i < n; i++){
    	 printf ("%d", a[i]);
    	 if (i == n-1) printf ("\n");
    	 else printf (" ");
    }
   
	return 0;
}