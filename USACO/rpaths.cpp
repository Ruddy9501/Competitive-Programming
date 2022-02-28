//Enero oro 2006
//Caminos Redundantes/rpaths
//Ruddy Guerrero Alvarez
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>

#define RAN 5005
using namespace std;

int nc, nd, x, y, r, k, CFC, la, id, newn, nod, c;
int Low[RAN], Td[RAN], Id[RAN], K, C[RAN];
bool M[RAN], mk[RAN];

stack <int>P;
queue <int>Q;
vector <int>V[RAN], v[RAN];

struct par{
       int x, y;
       bool mar;
       int bus_nod (int nod){
           if (nod == x)
               return y;
           return x;
       }
}A[RAN];

void cfc(int nod){
     P.push (nod);
     Low[nod] = Td[nod] = ++k;
     int la = V[nod].size();

     for (int i = 0; i < la; i++){
          int id = V[nod][i];
          if (!A[id].mar){
              A[id].mar = 1;
              int newn = A[id].bus_nod(nod);
              if (!Low[newn]){
                  cfc (newn);
                  if (Low[nod] > Low[newn])
                      Low[nod] = Low[newn];
              }
               else
                   if (!M[newn] && Td[newn] < Low[nod])
                       Low[nod] = Td[newn];
          }
     }

     if (Low[nod] == Td[nod]){
         CFC++, r = -1;
         while (!P.empty() && r != nod){
                r = P.top();P.pop();
                M[r] = 1;
                Id[r] = CFC;
         }
     }
}

void BFS(int xx){
    K++;
    mk[xx] = 1;
    for(Q.push(xx); !Q.empty(); Q.pop()){
        nod = Q.front();
        la = v[nod].size();
        if(la < 2)C[K]++;
        if(!la) C[K]--;

        for(int i = 0; i < la; i++){
            newn = v[nod][i];
            if(!mk[newn])
                mk[newn] = 1,
                Q.push(newn);
        }
    }
}
int main (){

    freopen ("rpaths.in", "r", stdin);
    freopen ("rpaths.out", "w", stdout);

    scanf ("%d %d", &nd, &nc);
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d", &x, &y);
         V[x].push_back(i);
         V[y].push_back(i);
         A[i] = (par){x, y, 0};
     }

     for (int i = 1;  i<= nd; i++)
          if (!Td[i])
              cfc(i);

     for (int i=1;i<=nd;i++){
        la = V[i].size();
        for(int j = 0; j < la; j++){
            id = V[i][j];
            newn = A[id].bus_nod(i);
            if(Id[newn] != Id[i])
                v[Id[i]].push_back(Id[newn]);
        }
     }

    for (int i = 1; i <= CFC; i++)
        if(!mk[i])
            BFS(i);

    if(K > 1)
        for(int i = 1; i <= K; i++)
            c += C[i]-2;
    else
        c = C[1];

    printf("%d", c/2+c%2);
    return 0;
}
