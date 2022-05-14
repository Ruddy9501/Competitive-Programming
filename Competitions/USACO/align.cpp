/*
************************************ 
** Ruddy Guerrero Alvarez         **
** Cuba--Villa Clara--Caibarien   **
************************************
*/
#include <cstdio>
#include <algorithm>

#define RAN 1000
#define oo 1 << 29

using namespace std;

int c, n, x, y, p1, p2, p3, p4, sol;
int S[RAN][3];

struct dos{
       int x, y, id;
       dos(int a = 0, int b = 0, int c = 0){
           x = a;
           y = b;
           id = c;
       }
       bool operator < (const dos &R)
       const{
             if(R.x != x)
                return R.x > x;
              else
                return R.y > y;   
       } 
}A[RAN];    

int main (){
    
    freopen("align.in","r",stdin);
    freopen("align.out","w",stdout);   	

    scanf("%d\n",&n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d %d\n", &x, &y);
        A[i] = dos( x, y, i);
    }
    
    for(int i = 1; i <= n-3; i++){    
        for(int j = i+1; j <= n-1; j++){
            p1 = A[j].x - A[i].x;
            p2 = A[j].y - A[i].y;
            for(int k = j+1; k <= n; k++){
                p3 = A[k].x - A[i].x;
                p4 = A[k].y - A[i].y;
                if(p1 * p4 == p2 * p3){
                   sol++;
                   S[sol][1] = i;
                   S[sol][2] = j;
                   S[sol][3] = k;
                }
            }
        }
    }
    
    printf("%d\n",sol);
    for(int i = 1; i <= sol; i++){
        printf("%d ",S[i][1]);
        printf("%d ",S[i][2]);
        printf("%d\n",S[i][3]);
    }
    
    return 0; 
    }
