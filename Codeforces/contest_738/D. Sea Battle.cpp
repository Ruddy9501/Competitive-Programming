/*
2016-11-22 03:59:03
https://codeforces.com/contest/738/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 2*1e5+5;
char A[10000000];
struct par{
       int tam, pos;
       bool operator <(const par &R)const {
       	    return tam < R.tam; 
       } 
} ;
 
priority_queue <par>Q;
vector <int> S;
 
int main(){
     
    int n, nb, tb, dis;
	scanf ("%d %d %d %d", &n, &nb, &tb, &dis);
 
	scanf ("%s", A+1);
	int la = strlen (A+1);
	A[++la] = '1'; 
	int ult = 0, can = 0;
    for (int i = 1; i <= la; i++){
    	 if (A[i] == '1' && i-ult >= tb){
             Q.push(par{i-ult-1, ult+1});
    	     can += (i-ult-1)/tb;
    	 }
    	 if (A[i] == '1') ult = i;
    }
    
    int c = 0; 
    while (can >= nb){
    	   can--;
    	   c++;
    	   par a = Q.top(); 
    	   Q.pop();
    	   S.push_back(a.pos+tb-1);
    	   a.pos = a.pos + tb;
    	   a.tam = a.tam - tb;
    	   if (a.tam >= tb) Q.push(a);   
    }
    
    printf ("%d\n", c);
    int l = (int)S.size();
    for (int i = 0; i < l; i++){
    	 if (i == 0)printf ("%d", S[i]);
    	  else printf (" %d", S[i]);
    }
    printf ("\n");
 
	return 0;
}