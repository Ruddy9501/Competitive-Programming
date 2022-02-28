/*
Ruddy Guerrero Alvarez
Caibarien -- Villa Clara
Tres rectas\3lines\USACO\
abril\oro
esto es un greedis
*/
#include <cstdio>
#include <algorithm>

#define MAX 999999999
#define RAN 50010
using namespace std;

int n, t,  a, b, ca, ina, inb, cb, ma, mb, inia, inib, fina, finb;
bool M[MAX];

struct dos{
       int val, id;
       bool operator <(const dos &R)
       const{
             return R.val > val;
       }
       }A[RAN], B[RAN];

int main (){

    freopen ("3lines.in","r",stdin);
    freopen ("3lines.out","w",stdout);

    scanf ("%d\n", &n);

   /* for (int i = 1;i <= n; i++){
         scanf ("%d %d\n", &a, &b);
         A[i].val = a;
         A[i].id = i;
         B[i].val = b;
         B[i].id = i;
    }

    sort (A + 1, A + n+ 1);
    sort (B + 1, B + n+ 1);

    for (int j = 1; j <= 3; j++){
         ca = 0;
         cb = 0;
         ma = 0;
         mb = 0;
         a = -1;
         b = -1;
         for (int i = 1; i <= n; i++){
              if (a == A[i].val && M[A[i].id] == false){
                  ca++;
                  if (ca > ma){
                      ma = ca;
                      inia = ina;
                      fina = ina + ca - 1;
                  }
              }
              else
                 if (M[A[i].id] == false){
                     a = A[i].val;
                     ca = 1;
                     ina = i;
                 }
              if (b == B[i].val && M[B[i].id] == false){
                  cb++;
                  if (cb > mb){
                      mb = cb;
                      inib = inb;
                      finb = inb + cb -1;
                  }
              }
              else
                  if (M[B[i].id] == false){
                      cb = 1;
                      b = B[i].val;
                      inb = i;
           }
         }
         if (ma == 0 && mb == 0){
             t += 1;
             M[ina] = true;
             continue;
         }
         if (ma > mb){
             t += ma;
             for (int i = inia; i <= fina; i++)
                  M[A[i].id] = true;
         }
          else{
             t += mb;
             for (int i = inib; i <= finb; i++)
                  M[B[i].id] = true;
          }
    }
*/
    if (t == n)
        printf ("1\n");
     else
        printf ("0\n");

    return 0;
    }
