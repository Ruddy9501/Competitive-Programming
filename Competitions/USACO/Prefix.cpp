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

#define RAN 1000
#define oo 1 << 29

using namespace std;

int sol1, sol2, tam, may, n;
char Mat[20005][105]; 

struct trie {
       trie *arb[264];
       int id;        
       }*P, Trie;

int main (){
    
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);   	
    
    scanf("%d\n", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%s\n",&Mat[i]);    
        tam = strlen(Mat[i]);
        P = &Trie;
        for(int j = 0; j <= tam; j++){
            if(P -> arb[Mat[i][j]] == NULL){
               P -> id = i;
               P -> arb[Mat[i][j]] = new trie();
               P = P -> arb[Mat[i][j]];
            }
             else{
               P = P -> arb[Mat[i][j]]; 
               if(j + 1 > may){
                  may = j + 1;
                  sol1 = P -> id;
                  sol2 = i;
               }    
             }
        }  
    }
    
    printf("%s\n",Mat[sol1]);
    printf("%s\n",Mat[sol2]);
     
    return 0; 
    }
