/*
2017-04-10 03:31:36
https://codeforces.com/contest/792/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5 + 5;
 
int q, la;
char A[RAN];
long long ini, fin, n;
 
struct par{
       long long ini, fin;
       par (long long ini, long long fin) : ini(ini), fin(fin) {}
};
 
stack <par> P;
 
int main(){
 
    scanf ("%lld %d", &n, &q);
    while (q--){
           long long u, piv;
    	     scanf ("%lld %s", &u, A);
           ini = 1, fin = n;
           la = strlen (A);
           
           while (!P.empty()) P.pop();  
            
           piv = (ini+fin)/2ll;
           //cout << u << "\n\n"; 
           while (piv != u) {
                  P.push(par(ini, fin));
                  if (piv < u) ini = piv + 1ll;
                   else fin = piv - 1ll;
                   piv = (ini+fin)/2ll;
                   //cout << ini << " " << fin << "\n";
           }
                     
           for (int i = 0; i < la; i++){
 
                if (A[i] == 'U'){
                	if (!P.empty()){
                		ini = P.top().ini;
                		fin = P.top().fin;
                		P.pop();
                	}
                	continue;
                }
                
                if (ini == fin) continue;
                
                P.push(par(ini, fin));   
 
                if (A[i] == 'L') fin = (ini+fin) / 2ll - 1ll;
                
                if (A[i] == 'R') ini = (ini+fin) / 2ll + 1ll;
           }
 
           printf ("%lld\n", (ini+fin)/2ll);
    }
 
	return 0;
}