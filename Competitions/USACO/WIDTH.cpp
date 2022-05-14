/*
Ruddy Guerrero Alvarez
Villa CLARA\ CAIBARIEN
Algorithmo DFS
PSN--Polonia 2005--D064  
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define RAN 1005
#define oo 1 << 29

using namespace std;
typedef pair<int, int>par;

int nniv, may, sol1, sol2, x, y, z, n, k;
int Td[RAN], Niv[RAN], Men[RAN], Max[RAN];
vector <par>V[RAN];

void dfs(int nod){
         int izq = V[nod][0].first;
         int der = V[nod][0].second;
         Niv[izq] = Niv[nod] + 1;
         Niv[der] = Niv[nod] + 1;
         if(Niv[izq] > nniv) 
            nniv = Niv[izq];
         if(izq != -1){
            dfs(izq);
         }
          else
            if(!Td[nod])
               Td[nod] = ++k;
         if(der != -1){
            if(!Td[nod])    
               Td[nod] = ++k;
            dfs(der);
         }
          else
            if(!Td[nod])
               Td[nod] = ++k;              
}

int main (){
    
    freopen("WIDTH.in","r",stdin);
    freopen("WIDTH.out","w",stdout);
    
    scanf("%d\n",&n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d\n",&x ,&y ,&z);
        V[x].push_back(par(y ,z));
    }
    
    Niv[1] = 1;
    dfs(1);
    

    fill(Men + 1, Men + nniv + 1, oo);
    for(int i = 1; i <= n; i++){
        if(Td[i] > Max[Niv[i]])
           Max[Niv[i]] = Td[i];
        if(Td[i] < Men[Niv[i]])
           Men[Niv[i]] = Td[i];            
    }
    
    for(int i = 1; i <= nniv; i++){
        if(may < Max[i] - Men[i] + 1){
           may = Max[i] - Men[i] + 1;
           sol1 = i;
           sol2 = Max[i] - Men[i] + 1;
        }
    }
    
    printf("%d %d\n",sol1,sol2);
    
    return 0;
    }
