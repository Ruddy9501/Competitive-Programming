/*
2017-07-25 16:47:47
https://codeforces.com/contest/831/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5+5;
const int oo = 1e9;
int n, a, Sum[RAN];
vector <int> v[RAN];
 
 
 
void uu(int pos){
     for (int i = pos; i <= n; i += (i&-i))
     	  Sum[i]++;
}
 
int qq(int pos){
	int sum = 0;
    for (int i = pos; i > 0; i -= (i&-i))
         sum += Sum[i];
    return sum;
}
 
 
int main(){
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d", &a);
    	 v[a].push_back(i);
    }
     
    int pos = 1;
    long long sol = 0ll; 
    for (int i = 1; i <= RAN; i++){
    	int l = (int)v[i].size();
    	if (l == 0) continue;
        int p = 0;
        for (; p < l && v[i][p] < pos; p++);
        
        if (p < l){
            for (int  j = p; j < l; j++){
                 sol = sol + (v[i][j]-pos+1) - (qq(v[i][j]) - qq(pos-1));
                 pos = v[i][j];
                 uu (pos);
                // printf ("%d pos: %d sol: %lld\n", ++c, pos, sol);
            }
        } 
        
        if (p > 0){
        	sol = sol + (n-pos+1) - (qq(n) - qq(pos-1));
            pos = 1;  
        	for (int j = 0; j < p; j++){
        		 sol = sol + (v[i][j]-pos+1) - (qq(v[i][j]) - qq(pos-1));
                 pos = v[i][j];
                 uu (pos); 
                 //printf ("%d pos: %d sol: %lld\n", ++c, pos, sol);
        	}
        }
    }
 
    printf ("%lld\n", sol);
 
	return 0;
}