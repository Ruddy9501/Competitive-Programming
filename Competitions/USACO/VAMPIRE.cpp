/*
Ruddy Guerrero Alvarez
11no
Túneles vampiros\vampire\
PSN\2012\11na Prueba Final
Dijktra 
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

#define RAN 2010
#define oo 1 << 29

using namespace std;
typedef pair <int, int>par;
struct R{
       int nod, cos, d;   
       R(int a, int c, int d1){
            nod = a;
            cos = c; 
            d = d1;
       } 
       bool operator <(const R &A)
       const {
             return A.cos < cos;
             } 
};

int nod, cos, newn, newc, s, t, nc, nd, x, y, z, d, sol, s1;
int C[RAN], S[RAN], T[RAN];
bool M[RAN][RAN];
vector <R> V[RAN];
priority_queue <R>Q;

int main(){
 
    freopen ("VAMPIRE.in","r",stdin);
    freopen ("VAMPIRE.out","w",stdout);
    
    scanf ("%d\n", &t);
    
    scanf ("%d %d\n", &nd, &nc);
    for (int i = 1; i <= nc; i++){
         scanf ("%d %d %d %d\n", &x, &y, &z, &d);
         V[x].push_back(R(y, z, d));
         V[y].push_back(R(x, z, d));
    }
    
    for (int i = 0; i <= nc; i++)
         T[i] = V[i].size(); 
    
    fill (C + 1, C + nd + 1, oo);
    
    sol = oo; 
    int con;
    Q.push(R(0, 0, 0));
    while (!Q.empty()){
           cos = Q.top().cos;
           nod = Q.top().nod;
           s = Q.top().d;
           Q.pop();
           for (int i = 0; i < T[nod]; i++){
                newn = V[nod][i].nod;
                newc = V[nod][i].cos + cos;
                s1 = s; 
                if (V[nod][i].d == 1)
                    s1 += V[nod][i].cos;
                if (s1 <= t){
                    if (newc < C[newn] || s1 < S[newn]){
                        if (C[newn] > newc){
                            C[newn] = newc;
                            if (S[newn] == 0)
                                S[newn] = s1;
                            if (newn == nd-1 && newc < sol ){
                                sol = newc;
                            }
                        } 
                         else
                            S[newn] = s1;         
                        Q.push(R(newn, newc, s1)); 
                        M[nod][newn] = M[newn][nod] = true;
                    }
                }     
           }
    }
    
    if (sol != oo)
        printf ("%d\n", sol);
     else
        printf ("-1\n");
 return 0;
}
