/*
Leonardo Fuentes(pototo O el pelli)
Ruddy Guerrero (el bello)
NACIONAL 2009 DIA 1C
////////////////////////
// ESTE ES EL NACIONAL//
//   MAS FACIL DE LA  //
//     HISTORIA       //
////////////////////////
*/
#include <cstdio>
#include <queue>

#define RAN 300
#define RAN1 600
using namespace std;

int F, C, R, con, c, s;
int A[255][255], P[250][250];

struct tres{
       int val, x, y;
       tres (int a = 0, int b = 0, int c = 0){
             val = a;
             x = b;
             y = c;
       }
       bool operator <(const tres &R)
       const {
              return R.val > val;
       }
};

priority_queue <tres>Q;

int main(){

    freopen ("PANT.in", "r", stdin);
    freopen ("PANT.out", "w", stdout);

    scanf ("%d %d\n", &F, &C);
    scanf ("%d\n", &R);
    for (int i = 1; i <= F; i++){
         for (int j = 1; j <= C; j++){
              scanf ("%d", &A[i][j]);
         }
    }

    while (con < F){
           con++;
           for (int i = 1; i <= C; i++){
                Q.push(tres(A[con][i], con, i));
                c++;
                if (c % R == 0){
                    P[Q.top().x][Q.top().y] = ++s;
                    Q.pop();
                }
           }
           con++;
           if (con <= F)
           for (int i = C; i >= 1; i--){
                Q.push(tres(A[con][i], con, i));
                c++;
                if (c % R == 0){
                    P[Q.top().x][Q.top().y] = ++s;
                    Q.pop();
                }
           }
    }

    while (!Q.empty()){
           P[Q.top().x][Q.top().y] = ++s;
           Q.pop();
    }

    for (int i = 1; i <= F; i++){
         printf ("%d", P[i][1]);
         for (int j = 2; j <= C; j++)
              printf (" %d", P[i][j]);
         printf ("\n");
    }

    return 0;
}
