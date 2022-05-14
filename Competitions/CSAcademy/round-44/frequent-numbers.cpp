#include <bits/stdc++.h>

using namespace std;

int n, k, a, C[1005], sol;

int main(){
    
    scanf ("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d", &a);
         C[a]++;
    }

    for (int i = 1; i <=1000; i++)
    	 if (C[i] >= k) sol++;

    printf ("%d\n", sol);


	return 0;
}