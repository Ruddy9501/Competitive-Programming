/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 1000000
#define MAX 500
#define oo 1 << 29

using namespace std;
typedef pair<int, int>par;

int nod, newn, newc, cos, n, sol, k, c, ini ;
int B[MAX][MAX], A[MAX][MAX], C[RAN];
bool M[RAN];
vector <par> V[RAN];
priority_queue <par>Q;

int main (){
    
    freopen("bowl.in","r",stdin);
    freopen("bowl.out","w",stdout);   	
    
    scanf("%d\n",&n);
    
    for(int i = 1; i <= n; i++){
        k++;
        for(int j = 1; j <= k; j++){
           scanf("%d",&A[i][j]);
           B[i][j] = ++c;
           if(i == 1)
              ini = A[i][j];
            else{
              V[B[i-1][j]].push_back(par(B[i][j], A[i][j])); 
              V[B[i-1][j-1]].push_back(par(B[i][j], A[i][j]));   
            }
        } 
    } 
    
  /*  for(int i = 1; i <= c; i++)
        for(int j = 0; j < V[i].size(); j++)
            printf("%d %d %d\n",i,V[i][j].first,V[i][j].second);
     */
   for(int i = 2; i <= c; i++)
       C[i] = -5;
    
    Q.push(par(ini,1));
    while(!Q.empty()){
        cos = Q.top().first;
        nod = Q.top().second;
        Q.pop();
        for(int i = 0; i < V[nod].size(); i++){
            newn = V[nod][i].first;c++;
            newc = V[nod][i].second + cos;
            if(newc > C[newn]){     
               C[newn] = newc;
               Q.push(par(newc,newn));
               if(sol < newc)
                  sol = newc; 
            }
        }
    } 
        
    printf("%d\n",sol);
    
    return 0;  
    }
