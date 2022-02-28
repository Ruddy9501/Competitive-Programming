/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2007-2008/enero/bronce
Baile de Disfraces/costume
AD-Hod
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, t, c;
long long s;
int C[1000005], A[20005];

int main (){

        freopen ("costume.in","r",stdin);
        freopen ("costume.out","w",stdout);

        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
             scanf ("%d", &A[i]);

        sort (A + 1, A + n + 1);
        
        c = 1;
        for (int i = 1; i <= m; i++){
             C[i] = C[i-1];
             while (i == A[c]){
                    C[i] += 1;
                    c++;
             }
        }    
        
        for (int i = 1; i <= n; i++){
             t = C[m-A[i]] - i;
             if (t > 0)
                 s += t; 
              else
                 break;      
        }
        
        printf ("%lld", s);  
}
