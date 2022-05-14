/*
Ruddy Guerrero Alvarez
Caibarien--Villa Clara
Tiempo de Elecciones\elect\
USACO\2007-2008\enero\broce
Greddy
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define RAN 50005

using namespace std;
typedef pair <int,int>par;

int n, m, a, may, sol;
int B[RAN];
priority_queue<par>Q;

int main (){
    
	freopen ("elect.in","r",stdin);
	freopen ("elect.out","w",stdout);
	
	scanf ("%d %d", &n, &m);
	
	for (int i = 1;i <= n; i++){
	     scanf ("%d %d\n", &a, &B[i]);
         Q.push(par(a,i));		 
	}
	
	for (int i = 1; i <= m; i++){
	     int id = Q.top().second;
	     Q.pop();
		 if (B[id] > may){
		     sol = id;
		     may = B[id];	 
		 }
	}
	
	printf ("%d\n",sol);
	
    return 0;
}
