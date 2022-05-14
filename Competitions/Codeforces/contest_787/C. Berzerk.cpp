/*
2017-03-29 18:20:08
https://codeforces.com/contest/787/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5;
int n, k1, k2, S1[RAN], S2[RAN];
string P[RAN], S[RAN];
 
int main(){
 
    cin >> n;
    cin >> k1;
    for (int i = 1; i <= k1; i++){
    	 cin >> S1[i];
    	 P[n-S1[i]] = "Win";
    }
 
    cin >> k2;
    for (int i = 1; i <= k2; i++){
    	 cin >> S2[i];
    	 S[n-S2[i]] = "Win";
    }
    
    bool flag = true;
    while (flag){
    	   flag = false;
		   for (int i = n-1; i > 0; i--){
		    	 bool mar = false;
		    	 if (P[i] == ""){
			    	 for (int j = 1; j <= k1; j++){
			    	 	  //cout << i << " " << S[(i+S1[j])%n] << " ";
			    	 	  
			    	 	  if (S[(i+S1[j])%n] == "Lose"){
			    	 	  	  P[i] = "Win";
			    	 	  	  mar = true;
			    	 	  	  flag = true;
			    	 	  }
 
			    	 	  if (S[(i+S1[j])%n] != "Win" && (i+S1[j])%n != 0){
			    	 	  	  mar = true;
			              //    break;
			    	 	  }
			    	 	
			    	 }
			   
 
				    if (!mar){
				    	flag = true; 
				    	P[i] = "Lose";
				    }
				}
 
                mar = false; //cout << " " << S[i] << "\n";
                if (S[i] == ""){
				    for (int j = 1; j <= k2; j++){
				    	  if (P[(i+S2[j])%n] == "Lose"){
			    	 	  	  S[i] = "Win"; 
			    	 	  	  mar = true;
			    	 	  	  flag = true;
			    	 	  }
			    	 	  if (P[(i+S2[j])%n] != "Win" && (i+S2[j])%n != 0){
			    	 	  	  mar = true;
			                //  break;
			    	 	  }
			    	 	
			    	 }
			   
 
				    if (!mar){
				    	flag = true; 
				    	S[i] = "Lose";
				    }
				}
    
	    }
    // cout << "\n";
    }
 
	for (int i = 1; i < n; i++){
		 if (P[i] == "") P[i] = "Loop";
		 if (i == n-1) cout << P[i] << "\n";
		  else cout << P[i] << " ";
	}
 
    for (int i = 1; i < n; i++){
		 if (S[i] == "") S[i] = "Loop";
		 if (i == n-1) cout << S[i] << "\n";
		  else cout << S[i] << " ";
	}
	return 0;
} 