#include <bits/stdc++.h>

using namespace std;
int n, c[40], sol;
char a[10000];

int main(){
	
    scanf ("%d", &n); 	
    scanf ("%s", a); 	
	
	for (int i = 0; i < n; i++) c[a[i]-'a']++;
	
	for (int i = 0; i < 26; i++)
	     if (c[a[i]-'a'] == 1 && sol == -1) sol = i;
	
	printf ("%c\n", 'a'+sol);
	
    return 0;
}
