/*
Censoring/plata/2015/febrero
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char A[1000015], B[1000015];
int la, lb, K[1000015], k, F[1000015], pos1, pos;
bool M[1000015];

int main(){

    freopen ("censor.in","r",stdin);
    freopen ("censor.out","w",stdout);

     scanf ("%s", A + 1);
     scanf ("%s", B + 1);

      la = strlen (A + 1);
      lb = strlen (B + 1);

      for (int i = 2; i <= lb; i++){
		   while (k > 0 && B[k + 1] != B[i])
		          k = F[k];
           if (B[k + 1] == B[i])
               k++;
           F[i] = k;
	  }


             k = 0;
             for (int i = 1; i <= la; i++){
                  if (M[i]) continue;
                  while (k > 0 && B[k + 1] != A[i])
                         k = F[k];
                  if (B[k + 1] == A[i])
		              k++;
                  if (k == lb){
                      pos1 = 0;
                      pos = -1;
                      while(pos1 < lb){
                            pos++;
                            if (M[i-pos]) continue;
                            M[i-pos] = true;
                            pos1++;
                      }
                      while (M[i-pos])pos++;
                      k = K[i-pos];
                      i -= (pos);
                      continue;
                  }
                  K[i] = k;
	         }

    for (int i = 1; i <= la; i++)
         if (!M[i])
             printf ("%c", A[i]);
    printf ("\n");

   return 0;
}
