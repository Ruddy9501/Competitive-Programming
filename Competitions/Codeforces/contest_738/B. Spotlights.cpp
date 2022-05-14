/*
2016-11-21 23:44:45
https://codeforces.com/contest/738/problem/B
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e3+5;
#define oo 1<<32
int mX[RAN], mY[RAN], MX[RAN], MY[RAN], A[RAN][RAN], n, m, sol;
 
int main (){
    
     
 
//    cin >> n >> m;
    scanf ("%d%d", &n, &m);
    fill (mY, mY + 1005, RAN);
    fill (mX, mX + 1005, RAN);
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++){
    		 //cin >> A[i][j];
    		 scanf ("%d", &A[i][j]);
    		 if (A[i][j]){
    		     mX[i] = min (mX[i], j);
    		     MX[i] = max (MX[i], j);
                 mY[j] = min (mY[j], i); 
                 MY[j] = max (MY[j], i); 
    		 }
    	}
 
    for (int i = 1; i <= n; i++) 
    	for (int j = 1; j <= m; j++){
    		 if (!A[i][j]){
    		 	 if (mX[i] < j) sol++;
    		 	 if (MX[i] > j) sol++;
    		 	 if (mY[j] < i) sol++;
    		 	 if (MY[j] > i) sol++;
    		 	 //cout << i << " " << j << " " << sol << "\n";
    		 }
    	} 
    
    cout << sol << "\n";
 
    return 0;
}