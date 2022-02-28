/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 10005
#define MIN -1005

using namespace std;

int n, num, tot, sol;

int main (){
    
    freopen("profits.in","r",stdin);
    freopen("profits.out","w",stdout); 
    
    scanf ("%d\n", &n);
    
    sol = MIN;
    
    for (int i = 1; i <= n; i++){
         scanf ("%d\n", &num);
         tot += num;
         if (tot > sol){
             sol = tot;
         }
         if (tot < 0)
             tot = 0;
    }  	
     
    printf("%d\n",sol); 
     
    return 0; 
    }
