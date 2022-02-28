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

#define RAN 100005
#define oo 1 << 29

using namespace std;

int newn, nod, n, ini, P[RAN], C[RAN];
queue <int>Q;
vector <int>V[RAN];

int main (){

    freopen("slowdown.in","r",stdin);
    freopen("slowdown.out","w",stdout);

    scanf ("%d\n", &n);

    for (int i = 1; i <= n-1; i++){
         scanf ("%d %d\n", &nod ,&newn);
         V[nod].push_back(newn);
         V[newn].push_back(nod);
    }

    Q.push(1);
    P[1] = -1;
    while (!Q.empty()){
           nod = Q.front();
           Q.pop();
           for (int i = 0; i < V[nod].size(); i++){
                newn = V[nod][i];
               if (!P[newn]){
                   P[newn] = nod;
                   Q.push(newn);
               }
           }
    }

    for (int i = 1; i <= n; i++){
         scanf ("%d\n", &nod);
         int cos = 0;
         int nod1 = nod;
         while (cos == 0 && nod1 != 1){
                cos = C[P[nod1]];
                nod1 = P[nod1];
         }
         printf ("%d\n",cos);
         C[nod] = cos + 1;
    }

    return 0;
    }
