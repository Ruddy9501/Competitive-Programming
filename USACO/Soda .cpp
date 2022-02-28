/*
Ruddy Guerrero Alvarez
Caibarien--Villa clara
Máquina de Soda\soda\USACO
2011\octubre\Oro
*/
#include <cstdio>
#include <queue>
#include <algorithm>
#define oo 1000000005

using namespace std;

struct uno{
       long long a;
       uno (long long b = 0){
            a = b;
       }
       bool operator <(const uno &R)
       const{
	        return R.a < a;
	   }	   
};

int sol, con, n;
long long x, y;
priority_queue <uno>Q, Q1;

int main (){
    
	freopen ("soda.in","r",stdin);
	freopen ("soda.out","w",stdout);
	
	scanf ("%d\n", &n);
	
	for (int i = 1; i <= n; i++){
	     scanf ("%I64d %I64d\n", &x, &y);
		 Q.push(uno(x));
		 Q1.push(uno(y));
	}
    
	Q.push(uno(oo));
	Q1.push(uno(oo));
	
	while (x != oo && y != oo){
	       x = Q.top().a;
		   y = Q1.top().a;
		   if (x <= y){
		       con++;
		       Q.pop();
		   }
		    else{
		       if (sol < con)
			       sol = con;
                con--;
                Q1.pop();				   
		    }
	}
	
	printf ("%d\n",sol);
	
    return 0;  
}
