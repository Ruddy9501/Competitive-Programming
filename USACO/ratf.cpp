/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
**USACO\2007-2008\abril\plata     **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 1000
#define oo 1 << 29

using namespace std;

int n1, n2, t, n, s;

void sol (int n){
     int n1 = (n + t) / 2;
     int n2 = n - n1;
     if (n1 - n2 == t && n2 > 0){
         sol (n2);
         sol (n1);
          }
     else
        s++;
}
int main (){
    
    freopen("ratf.in","r",stdin);
    freopen("ratf.out","w",stdout);   	
    
    scanf ("%d %d", &n, &t);
    
    sol (n); 
    
    printf ("%d\n",s);
    
    return 0; 
    }
