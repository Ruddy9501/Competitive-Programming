#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
int n, a[MAX], sum, sol;
map <int, bool> m;

int main(){

    scanf ("%d", &n);
    int mi = INT_MAX, ma = INT_MIN;
    for (int i = 1; i <= n; i++){
         scanf ("%d", &a[i]);
         sum += a[i];
         mi = min (mi, sum);
         ma = max (ma, sum); 
    }

    for (int i = mi; i <= ma; i++){
    	 m[i] = true;
    }
    
    sol = ma-mi+1;
    for (int i = 1; i < n; i++){
    	 if (a[i]){
    	 	 mi--;
    	 	 ma--;
    	 	 if (m.count(mi) == 0) sol++;
    	 }

    	 else{ 
            mi++;
            ma++;
            if (m.count(ma) == 0) sol++;
    	 }
    	 m[mi] = true;
    	 m[ma] = true;
    }
    
    printf("%d\n", sol);

	return 0;
}