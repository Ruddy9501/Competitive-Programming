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

#define RAN 300
#define oo 1 << 29

using namespace std;

int nod, newn, n, nc, i , k;
int Low[RAN], Td[RAN];
bool mar;
vector <int>V[RAN]; 

void DFS(int nod){
         Low[nod] = Td[nod] = ++k;
         for(int  i = 0; i < V[nod].size(); i++){
             int newn = V[nod][i];
             if(!Td[newn]){
                DFS(newn);
                Low[nod] <?= Low[newn];
                if(Td[nod] <= Low[newn] && !mar && nod != 1){
                   mar = true;
                   printf("%d\n",nod);   
                }
             }
              else
                Low[nod] <?= Td[newn];     
         }
     }

int main (){
    
    freopen("amigo.in","r",stdin);
    freopen("amigo.out","w",stdout);   	

    scanf("%d\n",&n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d",&nc);
        for(int j = 1; j <= nc; j++){
            scanf("%d",&newn);
            V[i].push_back(newn);           
        }
    }
    
    DFS(1);
    
    if(mar == false)
       printf("1\n");
    
    return 0; 
    }
