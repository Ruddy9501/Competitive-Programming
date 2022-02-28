/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/

#include <cstdio>
#include <algorithm>

#define RAN 25

using namespace std;

int M[RAN][RAN];
int n, s, r;

int main (){
    
    freopen("pktri1.in","r",stdin);
    freopen("pktri1.out","w",stdout);   	
    
    scanf("%d %d\n",&n ,&s);
    
    M[0][1] = s-1;
    for(int i = 1; i <= n; i++){
        s = M[i-1][i] + 1;
        r = i - 1;
        for(int j = i; j <= n; j++){
            while(s > 9)
               s = s - 9;
            M[i][j] = s;
            r++;
            s += r;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(M[i][j] != 0)    
               printf("%d",M[i][j]);
             else
               printf(" ");
            if(j == n)
               printf("\n");
             else
               printf(" ");
        } 
    }
    
    return 0; 
    }
