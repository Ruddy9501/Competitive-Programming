/*
Ruddy Guerrero Alvarez
Caibarien -- Villa Clara
 Lugar de Encuentro\meetplace\
 USACO\2011\marzo\plata
 LCA
*/
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define RAN 10010

using namespace std;

int newn, nod, a, b, m, n, t;
int LCA[RAN][20], Niv[RAN];
queue <int> Q;
vector <int> V[RAN];

main (){

     freopen ("meetplace.in","r",stdin);
     freopen ("meetplace.out","w",stdout);

     scanf ("%d %d\n", &n, &m);

     for (int i = 2; i <= n; i++){
	      scanf ("%d\n", &a);
		  V[a].push_back(i); 
	 }
     
	 Niv[1] = 1;
     for (Q.push(1); !Q.empty(); Q.pop()){
	      nod = Q.front();
		  for (int i = 0; i < V[nod].size(); i++){
		       newn = V[nod][i];
               Q.push(newn);
               Niv[newn] = Niv[nod] + 1;
               LCA[newn][0] = nod;
               t = (int) log2 (Niv[newn]);
               for (int j = 1; j <= t; j++){
			        if (LCA[newn][j - 1])
					    LCA[newn][j] = LCA[LCA[newn][j - 1]][j - 1];
			   }			   
		  } 
	 }

     for (int i = 1; i <= m; i++){
	      scanf ("%d %d\n", &a, &b);
		  if (Niv[a] < Niv[b])
              swap (a, b);
          t = (int) log2(Niv[a]);
		  for (int j = t; j >= 0; j--){
		       if (Niv[a] - (1 << j) >= Niv[b]){
			       a = LCA[a][j];
               }  
		  }
          if (a == b){
		      printf ("%d\n",a);
			  continue; 
		  }
		  t = (int) log2 (Niv[a]);
          for (int j = t; j >= 0; j--){
		       if (LCA[a][j] != LCA[b][j] && LCA[a][j]){
			       a = LCA[a][j];
				   b = LCA[b][j];
			   } 
		  } 
          printf ("%d\n", LCA[a][0]);		  
	 }  	 

}
