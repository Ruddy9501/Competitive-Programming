/*
Ruddy Guerrero Alvarez
11no
Caibarien -- Villa Clara
Prueba Final\ 9na-> mierdaaaaaaaaaaaaa
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, cero, uno, dos, tres, cuatro, nf, nc, f, c;
char M[510][510];

int main (){
    
    //freopen ("PROZORI.in","r",stdin);
    //freopen ("PROZORI.out","w",stdout);
    
    scanf ("%d %d\n", &n, &m);
    
    nf = (n * 4) + n + 1;
    nc = (m * 4) + m + 1;
    for (int i = 1; i <= nf; i++){
         scanf ("%s\n", M[i] + 1);
    } 
    
    f = 2;
    c = 2;
    
    for (int i = 1; i <= n; i++, f += 5){
         c = 2;
         for (int j = 1; j <= m; j++, c += 5)
              if (M[f][c] == '*' && M[f+1][c] != '*' &&
                  M[f+2][c] != '*' && M[f+3][c] != '*')
                  uno++;
               else    
              if (M[f+1][c] == '*' && M[f+2][c] != '*' &&
                  M[f+3][c] != '*')
                  dos++;
               else    
              if (M[f+2][c] == '*' && M[f+3][c] != '*')
                  tres++; 
               else   
              if (M[f+3][c] == '*')
                  cuatro++; 
               else
                cero++;
    }    
    
    printf ("%d %d %d %d %d\n", cero, uno, dos, tres, cuatro);
    
    return 0;
    }
