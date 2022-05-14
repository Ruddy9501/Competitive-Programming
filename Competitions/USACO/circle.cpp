/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
PSN EXPLORA#1
este ejercicio esta de pinga
se me va por tiempo no lo voy
a areglar porque no me da la gana 
Círculo de lajas/circle
!!!!El NEGRO ES FRUTABOMBA++++++++++++++++++++
*/
#include <cstdio>
#include <cstring>

#define RAN 105
using namespace std;

int n, m, c, con, r, sol, c1, ult;
char A[RAN], B[RAN], A1[RAN], X[RAN], Y[RAN], C[(1 << 11)][RAN];
bool mar;

void ig_A_B(){
     for (int i = 0; i < n; i++)
          A[i] = B[i];
}

void sig_estado(){
     for (int j = 1; j <= n; j++){
          if (j == n){
              if (A[j-1] == A[0])
                  B[j-1] = 'W';
               else
                  B[j-1] = 'B';
          }
          else
              if (A[j] == A[j-1])
                  B[j-1] = 'W';
               else
                  B[j-1] = 'B';
     }
}


void bus_ant(int k){
     X[0] = 'B';
     Y[0] = 'W';
     for (int i = 1; i < n; i++){
          if (C[k][i-1] == 'W')
              X[i] = X[i-1], Y[i] = Y[i-1];
           else{
              if (X[i-1] == 'W')
                  X[i] = 'B', Y[i] = 'W';
               else
                  X[i] = 'W', Y[i] = 'B';
           }
     }
}

bool compy (){
     mar = false;
     for (int k = r; k <= c; k++){
            con = -1;
     for (int i = 0; i < n; i++){
          c1 = 0;
          if (Y[0] == C[k][i]){
              c1 = 1, con = i+1;
              if (con == n)con = 0;
              while (Y[c1] == C[k][con] && con != i){
                     c1++;
                     con++;
                     if (con == n)
                         con = 0;
              }
          }
          if (c1 == n)
         return 1;
     }

     }
     return 0;
}


int main(){

    freopen ("circle.in", "r", stdin);
    freopen ("circle.out", "w", stdout);

    scanf ("%d %d\n", &n, &m);
    scanf ("%s", A);



    for (int i = 1; i <= m; i++){
         sig_estado();
         ig_A_B();
    }

     for (int i = 0; i < n; i++)
          A1[i] = A[i];

    c = 1;ult = 1;
    for (int i = 0; i < n; i++)
         C[c][i] = A[i];

    for (int i = 1; i <= m; i++){
         r = c+1;
         for (int k = ult; k < r; k++){
              bus_ant (k);
              c++;
              for (int j = 0; j < n; j++)
                  C[c][j] = X[j];
              mar = compy ();
              if (mar == 0){
                  c++;
                  for (int j = 0; j < n; j++)
                       C[c][j] = Y[j];
              }
         }
         ult = r;
    }

    sol = c-r+1;
    for (int i = r; i <= c; i++){
         for (int j = 0; j < n; j++)
              A[j] = C[i][j];
         for (int j = 1; j <= m; j++){
              sig_estado();
              ig_A_B();
         }
         mar = 0;
         for (int j = 0; j < n && mar == false; j++)
              if (A[j] != A1[j])
                  mar = 1;
         if (mar == 1)
             sol--;
    }
    printf ("%d\n", sol);

    return 0;
}
