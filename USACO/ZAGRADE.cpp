/*
Ruddy Guerrero Alvarez
11no
Caibarien -- Villa Clara
Prueba final\ 9na 
*/
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int a, m, n, c, r;
char A[210];
string S[100000];
bool M[210];
stack <int>P;
struct dos{
       int fin, ini;
}B[12];

void com(int p){
     for (int i = p; i <= c; i++){
          M[B[i].ini] = true;
          M[B[i].fin] = true;
          com (i+1);
          M[B[i].ini] = false;
          M[B[i].fin] = false;          
     } 
     a++;
     for (int j = 1; j <= n; j++){
          if (M[j] != true)
              S[a] += A[j];
     }
}

int main (){

    freopen ("zagrade.in","r",stdin);
	freopen ("zagrade.out","w",stdout);
     
	scanf ("%s", A + 1);
    
	n = strlen (A + 1);
    for (int i = 1; i <= n; i++){
         if (A[i] == '(') {
		     P.push(i);
	         continue;
         }
         if (A[i] == ')'){
		     B[++c].ini = P.top();
		     B[c].fin = i;
		     P.pop();
		 }		  
	}
    
    com (1);
	
	sort (S + 1, S + a);
	
	for (int i = 1; i < a; i++)
         if (S[i] != S[i-1])
             printf ("%s\n", S[i].c_str());   
    
	
    return 0;
   }
