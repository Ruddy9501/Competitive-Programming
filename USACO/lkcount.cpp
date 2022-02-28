/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
Conteo de posos\lkcount
USACO\2010-11\October\Problems\Silver\
*/
#include <queue>
#include <cstdio>
#include <cstring>

#define RAN 1010
using namespace std;
typedef pair<int, int>par;

const int mf[] = { 0,  0,  1,  1,  1, -1, -1, -1},
          mc[] = {-1,  1,  0, -1,  1,  1, -1,  0};

int nf, nc, sol, i, j, f, c;
char A[RAN][RAN];
bool mar, M[RAN][RAN];

queue <par>Q;

void bfs (){
     Q.push(par(i, j));
     while (!Q.empty()){
            f = Q.front().first;
            c = Q.front().second;
            Q.pop();
            for (int i = 0; i < 8; i++){
                 int nf = f + mf[i];
                 int nc = c + mc[i];
                 if (M[nf][nc] == 0 && A[nf][nc] == 'W'){
                     M[nf][nc] = 1;
                     Q.push(par(nf, nc));
                 }
            }
     }
}

int main(){

    freopen ("lkcount.in", "r", stdin);
    freopen ("lkcount.out", "w", stdout);

    scanf ("%d %d", &nf, &nc);
    for (i = 1; i <= nf; i++){
         scanf ("\n");
         for (j = 1; j <= nc; j++)
              scanf ("%c", &A[i][j]);
    }

    for (i = 1; i <= nf; i++){
         for (j = 1; j <= nc; j++){
              if (A[i][j] != 'W' || M[i][j])continue;
              bfs ();
              sol++;
         }
    }

    printf ("%d\n", sol);

    return 0;
}
