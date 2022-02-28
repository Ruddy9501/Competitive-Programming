/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
** Apilamiento de cartas\cheat\   **
** USACO\2007\diciembre\          ** 
** bronce\Brute Force             **
************************************
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 100000

using namespace std;

int con, N, K, P, a, c;
int A[RAN];
queue <int>Q; 

int main (){
    
    freopen("cheat.in","r",stdin);
    freopen("cheat.out","w",stdout);   	
    
    scanf ("%d %d %d\n", &N, &K, &P);
    
    for (int i = 1;i <= K; i++)
         Q.push(i);
    
    while (!Q.empty()){
           con++;
           if (con == N){
               A[++c] = Q.front();
               con = 0;
           }
           Q.pop();
           for (int i = 1; i <= P && !Q.empty(); i++){
                a = Q.front();
                Q.pop();
                Q.push(a);
           }          
    }     
    
    sort (A + 1, A + c + 1);
    
    for (int i = 1; i <= c; i++)
         printf ("%d\n",A[i]);
        
    return 0; 
    }
