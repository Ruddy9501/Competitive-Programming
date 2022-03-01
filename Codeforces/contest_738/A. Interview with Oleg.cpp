/*
2016-11-21 22:43:18
https://codeforces.com/contest/738/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
char A[100000];
 
int is_ogo(int p, int l){
    int i = p; 
	for (; i+2 < l; i++){
		 if (A[i] == 'o' && A[i+1] == 'g' && A[i+2]=='o')
		 	 i += 1;
		  else break; 	 
	}
	//if (i != p) i++;
 
	//cout << i << " " << p << "\n";
	return i;
}
 
int main (){
    int l; 
    cin >> l;
    cin >> A;
    //int l = strlen (A);
    for (int i = 0; i < l; i++){
    	 int a = is_ogo(i, l);
    	 //cout << i << " " << a << "\n";
    	 if (a <= i) cout << A[i];
    	  else{
    	  	 cout << "***";
    	  	 i = a;
    	  }
    }
    cout << "\n"; 
	return 0;
}