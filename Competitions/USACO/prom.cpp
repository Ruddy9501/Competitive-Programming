/*
Ruddy Guerrero Alvarez
12mo
USACO/2006/enero/plata
El Prom Bovino/prom
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int nd, nc, con,a, s, cn, b, nod, newn, sol, Id[100009];
bool M[100009], M1[100009];
vector <int>V[100009];
queue <int>Q;

void bfs(int nod, int con){
         Q.push(nod);
         while (!Q.empty()){
                nod = Q.front();
                Q.pop();
                for (int j = 0; j < V[nod].size(); j++){
                     newn = V[nod][j];
                     if (M[newn] == false){
                         M[newn] = true;
                         cn++;
                         Q.push(newn);
                     }
                      else{
                         Id[newn] = con;
                      }
                }
         }

}

void bfs1 (int nod, int con){
         Q.push(nod);
         bool mar = false, mar2 = false;
         while (!Q.empty()){
                nod = Q.front();
                Q.pop();
                for (int j = 0; j < V[nod].size(); j++){
                     newn = V[nod][j];
                     mar2 = true;
                     if (M1[newn] == false){
                         if (Id[newn] != con)
                             mar = true;
                         M1[newn] = true;
                         Q.push(newn);
                     }
                }
         }
         if (mar == false && mar2 == true)
             sol++;
}
int main(){

    freopen ("prom.in", "r", stdin);
    freopen ("prom.out", "w", stdout);

    scanf ("%d %d", &nd, &nc);
    for (int i = 1; i <= nc; i++){
         scanf("%d %d", &a, &b);
         V[a].push_back(b);
         V[b].push_back(a);
    }

    for (int i = 1; i <= nd; i++){
         if (M[i] == false){
             con++;
             bfs (i, con);
             bfs1 (i, con);
         }
    }

    printf ("%d", sol);

    return 0;
}
