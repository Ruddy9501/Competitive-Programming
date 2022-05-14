/*
2015-09-16 20:31:18
https://codeforces.com/contest/579/problem/C
*/
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
double x, y, x1, x2, sol1, sol2;
long long piv, ini, fin;
 
int main(){
 
    scanf ("%lf %lf", &x, &y);
 
    if (y > x){
        printf ("-1\n");
        return 0;
    }
 
    x1 = y+x;
    x2 = -(y-x);
 
    sol1 = sol2 = 1000000009;
 
    fin = 100000000000009;
    ini = 1;
 
    while (ini < fin){
 
           piv = (ini+fin)/2;
 
           if (x1/((double)2*piv) >= y){
               ini = piv+1;
               sol1 = piv;
           }
           else
               fin = piv;
    }
 
    if (x1/((double)2*fin) >= y){
           sol1 = piv;
    }
    if (x1/((double)2*ini) >= y){
           sol1 = piv;
    }
    fin = 100000000000009;
    ini = 1;
 
    while (ini < fin){
 
           piv = (ini+fin)/2;
 
           if (x1/((double)2*(double)piv) >= y){
               ini = piv+1;
               sol2 = piv;
           }
           else
               fin = piv;
    }
 
    if (x2/((double)2*fin) >= y){
           sol2 = piv;
    }
    if (x2/((double)2*ini) >= y){
           sol2 = piv;
    }
 
    if (sol1 <= sol2) printf ("%.12lf\n", x1/(sol1*(double)2));
    else if (sol1 > sol2) printf ("%.12lf\n", x2/(sol2*(double)2));
 
    return 0;
}