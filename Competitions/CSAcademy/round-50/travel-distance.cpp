#include <bits/stdc++.h>


using namespace std;

int x, y;
char A[1000000];

int main(){

    scanf ("%s", A);
    int la = strlen (A);
    for (int i = 0; i < la; i++){
         char a = A[i];  
    	 if (a == 'N') x++;
    	 if (a == 'S') x--;
    	 if (a == 'E') y++;
    	 if (a == 'W') y--;
    }

    printf ("%d\n", abs(x) + abs(y));

	return 0;
} 