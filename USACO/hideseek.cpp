/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/open/plata
Escondidas/hideseek
disktra
*/
#include <queue>
#include <cstdio>
#include <algorithm>

#define RAN 20005
#define oo 1 << 30
using namespace std;
typedef pair<int, int>par;

int nd, nc, a, b, nod, cos, newn;
vector <int>V[RAN];
priority_queue<par, vector<par>, greater<par> >Q;

struct dos{
       int c, id;
       bool operator <(const dos &R)
       const {
           if (R.c != c)
               return R.c < c;
           return R.id > id;
       }
}C[RAN];

int main(){

    freopen ("hideseek.in", "r", stdin);
    freopen ("hideseek.out", "w", stdout);

    scanf ("%d %d", &nd, &nc);
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d", &a, &b);
         V[a].push_back(b);
         V[b].push_back(a);
    }

    for (int i = 1; i <= nd; i++){
         C[i].id = i;
         C[i].c = oo;
    }

    Q.push(par(0, 1));
    C[1].c = 0;
    while (!Q.empty()){
           cos = Q.top().first;
           nod = Q.top().second;
           Q.pop();
           for (int i = 0; i < V[nod].size(); i++){
                newn = V[nod][i];
                if (C[newn].c > cos+1){
                    C[newn].c = cos + 1;
                    Q.push(par(cos+1, newn));
                }
           }
    }

    sort (C + 1, C + nd + 1);

    printf ("%d %d ",C[1].id, C[1].c);

    a = 1;
    while (C[a].c == C[a+1].c)
           a++;

    printf ("%d\n", a);

    return 0;
}
