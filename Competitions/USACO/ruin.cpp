/*
Ruddy Guerrero Alvarez
VILLA CLARA -> CAIBARIEN
PSN 2013 PRUEBA EXPLORTORIA #2
AD-HOD
La Ruina más antigua/ruin                                                                        
*/
#include <cstdio>
#include <algorithm>

#define RAN 5005
using namespace std;

int n, X[RAN], Y[RAN], x1, x2, y1, y2, dx, dy, sol;
bool M[RAN][RAN];

bool fe(int x, int y){
     if (x < 0 || y > 5000 ||
         x > 5000 || y < 0)
         return 0;
     return M[x][y];
}

int main(){

    freopen ("ruin.in", "r", stdin);
    freopen ("ruin.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%d %d", &X[i], &Y[i]);
         M[X[i]][Y[i]] = true;
	}

	for (int i = 1; i <= n; i++){
         for (int j = 1; j <= n; j++){
		      dx = X[i] - X[j];
			  dy = Y[i] - Y[j];
			  x1 = X[i] - dx + dy;
			  y1 = Y[i] - dx - dy;
			  x2 = X[i] + dy;
			  y2 = Y[i] - dx;
			  if (fe(x1, y1) && fe(x2, y2))
			      sol = max (sol, dx*dx + dy*dy);
		 }
	}

    printf ("%d\n", sol);

    return 0;
}
