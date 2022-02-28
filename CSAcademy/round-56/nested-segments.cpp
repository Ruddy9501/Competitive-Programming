#include <bits/stdc++.h>

using namespace std;

int n;

struct par{
       int x, y;
}a[10005];

int main(){
	
	scanf ("%d", &n);
	for (int i = 0;i < n; i++) scanf ("%d%d", &a[i].x,&a[i].y);
	
	int sol = 0;
	for (int i = 0; i < n; i++){
	     int ok = 0; 
	     for (int j = 0; j < n; j++)
	          if (j != i && a[j].x < a[i].x && a[i].y < a[j].y)
	              ok = 1;
	     sol += ok;         
	}
	
	printf ("%d\n", sol);
	
    return 0;	
}
