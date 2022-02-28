/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 1005
#define MAX 10005
#define oo 1 << 29

using namespace std;

int sol, tot, nc, np, nd, x, y, z, s;
int *P;
int M[RAN][RAN], A[MAX];

int main (){
    
    freopen("bestspot.in","r",stdin);
    freopen("bestspot.out","w",stdout);   	
     
    scanf("%d %d %d\n", &nd, &np, &nc);
    
    for(int i = 1; i <= np; i++)
        scanf("%d\n",&A[i]);
    
    for(int i = 1; i <= nd; i++)
        fill(M[i] + 1, M[i] + nd + 1, oo);
    
    for(int i = 1; i <= nc; i++){
        scanf("%d %d %d\n", &x, &y, &z);
        M[x][y] = z;
        M[y][x] = z;
    } 
    
    for(int i = 1; i <= nd; i++)
		for(int j = 1; j <= nd; j++)
		    if(M[j][i])
				for(int k = 1; k <= nd; k++)
					if(M[i][k] && (!M[j][k] || M[j][k] > M[j][i] + M[i][k])) 
                       M[j][k] = M[j][i] + M[i][k];
    s = oo;
   
    for(int i = 1; i <= nd; i++)
        M[i][i] = 0;
    
    for(int k = 1; k <= nd; k++){
        tot = 0;
        for(int j = 1; j <= np; j++)
                tot += M[k][A[j]];    
        if(s > tot){
           s = tot;
           sol = k; 
        }
    }
        
    printf("%d\n",sol);
    
    return 0; 
    }
