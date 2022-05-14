/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/

#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 264
#define oo 1 << 29

using namespace std;

int sol, nf, nm;
char car;

struct trie{
       trie *arb[RAN];       
       }*P, Trie;

int main (){
    
    freopen("PHRASE.in","r",stdin);
    freopen("PHRASE.out","w",stdout);   	
    
    scanf("%d %d\n",&nf ,&nm);
    
    for(int i = 1; i <= nf; i++){
        P = &Trie;
        car = 'a';
        while( car != '\n' ){
              scanf("%c",&car);
              if(P -> arb[car] == NULL)
                 P -> arb[car] = new trie();
              P = P -> arb[car];   
        }
    }
    
    for(int i = 1;i <= nm; i++){
        P = &Trie;
        car = 'a';
        while(car != '\n'){
              scanf("%c",&car);
              if(car == '\n')
                 sol++;
              if(P -> arb[car] != NULL){
                 P = P -> arb[car];
              }   
               else
                 while(car != '\n'){
                       scanf("%c",&car);
                 } 
        }
    }
    
    printf("%d\n",sol);
    
    return 0; 
    }
