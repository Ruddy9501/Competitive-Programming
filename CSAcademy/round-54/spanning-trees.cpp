#include <bits/stdc++.h>

using namespace std;

int n, k;
struct tres{
       int x, y, z;
};
vector <tres> s;

int main(){
   
    scanf ("%d%d", &n, &k);

    if (n == 2 && k == 0){
    	printf ("-1\n");
    	return 0;
    }

    if (n == 3 && k == 0){
    	printf ("-1\n");
    	return 0;
    }

    int r = n;
    for (int i = 1; i <= k; i++)
    	 s.push_back ((tres){i, i+1, r--});
    
    for (int i = k+1; i < n; i++)
    	 s.push_back ((tres){i, i+1, r--});
    

    if (k == 0){
	    r = n+1;
	    if (2 < n)
	    	s.push_back ((tres){2, n, r++});
	    for (int i = k+3; i <= n; i++) 	
	    	s.push_back ((tres){1, i, r++});
	}

	else{
		r = n+1;
		for (int i = k+2; i <= n; i++)
			 s.push_back ((tres){1, i, r++});
	} 
    printf ("%d\n", (int)s.size()); 
    for (auto a : s)
    	 printf ("%d %d %d\n", a.x, a.y, a.z);

    return 0;
}