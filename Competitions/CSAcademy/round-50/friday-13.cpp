#include <bits/stdc++.h>

using namespace std;

int M[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int d, sol = 0;
string s;
int main(){
    
    cin >> s;

    if (s == "Monday") d = 0;  
    if (s == "Tuesday") d = 1;  
    if (s == "Wednesday") d = 2;  
    if (s == "Thursday") d = 3;  
    if (s == "Friday") d = 4;  
    if (s == "Saturday") d = 5;  
    if (s == "Sunday") d = 6;  
    
    for (int i = 0; i < 12; i++){
    	 for (int j = 1; j <= M[i]; j++){
    	 	  if (j == 13 && d == 4) sol++;
    	 	  d = (d+1) % 7;
    	 }
    }

    printf ("%d\n", sol);

	return 0;
} 