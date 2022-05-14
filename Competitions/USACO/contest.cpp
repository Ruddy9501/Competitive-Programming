/*
Ruddy Guerrero Alvarez
Caibarien -- Villa Clara
Competencia Vacuna\contest\
USACO\2008\enero\plata
Floyd Warshall
*/
#include <cstdio>
#include <algorithm>
#define RAN 4505

using namespace std;

int n, m, sol, c, a, b;
bool M[RAN][RAN];

main (){

     freopen ("contest.in","r",stdin);
     freopen ("contest.out","w",stdout);

     scanf ("%d %d\n", &n, &m);
     
     for (int i = 1; i <= n; i++)M[i][i] = true;
     
     for (int i = 1; i <= m; i++){
	      scanf ("%d %d\n", &a, &b);
		  M[a][b] = true;
	 }

	 for (int k = 1; k <= n; k++){
	      for (int i = 1; i <= n; i++){
		       if (M[i][k] == true){
			       for (int j = 1; j <= n; j++)
				        if (M[k][j] == true)
						    M[i][j] = true;
			   }
		  }
	 }

	 for (int i = 1; i <= n; i++){
	      c = 0;
		  for (int j = 1; j <= n; j++)
		       if (M[i][j] == false && M[j][i] == false)
		           break;
                else
                   c++;
		  if (c == n)
		      sol++;
	 }
         
	 printf ("%d\n",sol);
}
