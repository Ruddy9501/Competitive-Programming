#include <bits/stdc++.h>

using namespace std;

char a[10000];

int main(){

    scanf ("%s", a+1);
    int l = strlen (a+1);
    for (int i = 1; i <= l; i++){
    	 if (a[i] == 'B' || a[i] != a[i-1]) printf ("%c", a[i]);
    }printf ("\n");

	return 0;
}