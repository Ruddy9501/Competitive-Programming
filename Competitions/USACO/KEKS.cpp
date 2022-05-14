/*
Ruddy Guerrero Alvarez
Caibarien -- Villa Clara
11no
Prueba Final\10ma
*/
#include <stack>
#include <cstdio>
#include <algorithm>

#define RAN 500100

using namespace std;

int n, m, c, a, con;
char A[RAN];
stack <int> P, S;

int main(){

    freopen ("KEKS.in","r",stdin);
    freopen ("KEKS.out","w",stdout);

    scanf ("%d %d\n", &n, &m);
    c = m;

    for (int i = 1; i <= n; i++){
         scanf ("%c", &A[i]);
         A[i] -= 48;
    }

    P.push (99999);
    P.push(A[1]);
    con = 1;
    for (int i = 2; i <= n; i++){
         a = P.top();
         if (a < A[i] && m != 0){
             while (a < A[i] && c != 0){
                    P.pop();
                    c--;
                    con--;
                    a = P.top();
             }
             P.push (A[i]);
             con++;
             continue;
         }
         if (a >= A[i] && con + m < n){
             P.push(A[i]);
             con++;
         }
    }

    while (!P.empty()){
           S.push(P.top());
           P.pop();
    }

    S.pop();
    while (!S.empty()){
           printf ("%d", S.top());
           S.pop();
    }

    printf ("\n");

 return  0;
}
