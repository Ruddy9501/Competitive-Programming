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

#define RAN 100000
#define oo 1 << 29

using namespace std;

stack <int>P, P1;
vector <int>V1[RAN], V2[RAN];
int nod, newn, i, c, N, Cu, Cb, S[RAN], E[RAN], Td[RAN], Low[RAN], k, k1;
int x, y, r, ey, ex, sy, sx, Sol1[RAN][2], Sol2[RAN][2], Low1[RAN], Td1[RAN];
bool M[RAN], mar, mar1, M1[RAN];

void cfc(int nod){
        P.push(nod);
        Low[nod] = Td[nod] = ++k;
        for (int i = 0; i < V1[nod].size(); i++){
             int newn = V1[nod][i];
             if (!Low[newn]){
                 cfc(newn);
                 Low[nod] <?= Low[newn]; 
             }
             else
               if(!M[newn])
                  Low[nod] <?= Td[newn]; 
        }
        if(Low[nod] == Td[nod] && !M[nod]){
           M[nod] = true;
           c = 0;
           while(!P.empty()){
                 c++;
                 nod = P.top();
                 M[nod] = true;
                 if(c >= 2){
                    mar = true;
                 }
                 P.pop();
           } 
        }
} 
void cfc1(int nod){
        P1.push(nod);
        Low1[nod] = Td1[nod] = ++k1;
        for (int i = 0; i < V2[nod].size(); i++){
             int newn = V2[nod][i];
             if (!Low1[newn]){
                 cfc1(newn);
                 Low1[nod] <?= Low1[newn]; 
             }
             else
               if(!M1[newn])
                  Low1[nod] <?= Td1[newn]; 
        }
        if(Low1[nod] == Td1[nod] && !M1[nod]){
           M1[nod] = true;
           c  = 0;
           while(!P1.empty()){
                 c++;
                 nod = P1.top();
                  M1[nod] = true;
                 if(c >= 2){
                    mar1 = true;
                 }
                 P1.pop();
           } 
        }
} 

int main (){
    
    freopen("DIZZY.in","r",stdin);
    freopen("DIZZY.out","w",stdout);   	
    
    scanf ("%d %d %d\n", &N, &Cu, &Cb);
    
    for (int i = 1; i <= Cu; i++){
         scanf ("%d %d\n", &x, &y);
         E[y]++;
         S[x]++;
         V1[x].push_back(y);
         V2[x].push_back(y); 
    }
    
    for (int i = 1; i <= Cb; i++){
         scanf ("%d %d\n", &x, &y);
         r = E[y] - E[x];
         if (r >= 0){
             V1[x].push_back(y);
             ey = 1;
             Sol1[i][1] = x;
             Sol1[i][2] = y;
         }
          else{
             V1[y].push_back(x);
             ex = 1;
             Sol1[i][1] = x;
             Sol1[i][2] = y;
             }
         r = S[y] - S[x];
         if (r >= 0){
             V2[y].push_back(x); 
             sy = 1;
             Sol2[i][1] = y;
             Sol2[i][2] = x;
         }
         else{
              V2[x].push_back(y);
              sy = 1;
              Sol2[i][1] = y;
              Sol2[i][2] = x;
         } 
         E[x] += ex;
         E[y] += ey;
         S[x] += sx;
         S[y] += sy;   
          
    } 
    
    cfc(1);
    if(mar != true){
       for(int i= 1; i <= Cb; i++)
           printf("%d %d\n",Sol1[i][1], Sol1[i][2]);
       return 0;
    }
    c = 0;
    cfc1(1);
    if(mar1 != true){
       for(int i= 1; i <= Cb; i++)
           printf("%d %d\n",Sol2[i][1], Sol2[i][2]);
       return 0;
    }
    printf("-1\n");
    return 0; 
    }
