/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int t, n, s, num, sol;
double frac, f, d;

int main (){
    
    freopen("roots.in","r",stdin);
    freopen("roots.out","w",stdout);   	
    
    scanf("%d\n",&t);
    scanf("%d",&num);
    
    d = 1.0;
    for(int i = 1; i <= t; i++)
        d *= 10.0; 
    
    frac = num / d;
    
    for(int i = 1; i <= 1000000; i++){
        n = (frac + i) * (frac + i) + 0.3;
        s = sqrt(double(n));
        f = sqrt(double(n));
        f = ( f  - s) * d;
        sol = f;
        if(sol == num){
           printf("%d\n",n);
           break;
        } 
    }
     
    return 0; 
    }
