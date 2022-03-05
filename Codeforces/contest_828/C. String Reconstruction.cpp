/*
2017-07-11 20:59:25
https://codeforces.com/contest/828/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, p, fin;
char A[2000010], S[2000005];
struct nodo{
       int sum;
       char car;
} St[2000005*4];
 
int update(int ini, int fin, int p, int a, int b){
     
    if (ini > b || fin < a) return St[p].sum;
    if (St[p].sum == fin-ini+1) return St[p].sum;
 
    if (a <= ini && fin <= b){
    	for (int i = ini; i <= fin; i++) 
    		 S[i] = A[i-a];
    	return St[p].sum = fin-ini + 1;
    }
    
 
    int piv = (ini+fin)/2;
    return St[p].sum = update(ini, piv, p*2, a, b) + update(piv+1, fin, p*2+1, a, b);
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie (0);
    cout.tie(0);
 
    cin >> n; 
    fill (S,S+2000005, 'a');
    for (int i = 0; i < n; i++){
    	 cin >> A >> m;
    	 int la = strlen (A) - 1;
         for (int i = 0; i < m; i++){
         	  cin >> p;
         	  update (1, 2000000, 1, p, p+la);
         	  fin = max(fin, p+la);
         } 
    } 
    //cout << fin << "\n";
    for (int i = 1; i <= fin; i++) cout << S[i];
    cout << "\n";
 
	return 0;
}