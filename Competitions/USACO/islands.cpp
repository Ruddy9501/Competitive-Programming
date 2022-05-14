/*
Ruddy Guerrero Alvarez
Caibarien -- Villa Clara
PSN\ Pruebas finales\ Prueba # 5\USACO/2011/abrir
Islas\ islands 
*/
#include <cstdio>
#include <algorithm>

#define RAN 100010
using namespace std;

long long n, sol, s;
bool M[RAN], m;
struct dos{
       long long val, id;
       bool operator <(const dos &R)
       const{
             return R.val > val;
             }
       }A[RAN];

int main(){
    
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    
    scanf ("%I64d", &n);
    
    for (int i = 1; i <= n; i++){
         scanf ("%I64d", &A[i].val);
         A[i].id  = i;   
    }
    
    sort (A + 1, A + n  + 1);
   
    sol = M[0] = M[n+1] = true; 
    for (int i = 1; i <= n; i++){        
         M[A[i].id] = true;
		 if (!M[A[i].id + 1] && !M[A[i].id - 1])
             sol++;
          else
             if (M[A[i].id + 1] && M[A[i].id - 1])
                 sol--;
         if (sol > s && A[i].val != A[i+1].val)
             s = sol;
    }
     
    printf ("%I64d\n", s); 
	
 return 0;
}

