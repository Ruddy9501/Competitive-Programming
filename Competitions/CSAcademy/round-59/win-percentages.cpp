#include <bits/stdc++.h>

using namespace std;

int g1, g2, p1, p2, s1, s2;

int f(int a, int b){
    double x = 1.0 * a/b * 100;
    return floor(x);
}

int main(){
	
	scanf ("%d %d %d %d", &g1, &p1, &g2, &p2);
	
	
	for (int i = 0; i <= g1; i++){
	     
	     if (p1 == f(i, g1)){
			 s1 = i; 
		     break;
		 }
	}
	
	
	//printf ("%d\n", f(g2, g2));
	
	for (int i = g2; i >= 0; i--){
	     if (p2 == f(i, g2)){
			 s2 = i;
		     break;
		 }
	}
	
	
	
	printf ("%d\n", min(g2-g1,s2-s1));
	
    return 0;	
}
