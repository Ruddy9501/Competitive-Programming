/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
USACO/2008-2009/open/plata
Línea Vacuna/cline
brute-forse
*/
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int n, val, con;
char car, car1;
deque <int>Q;

int main(){

    freopen ("cline.in", "r", stdin);
    freopen ("cline.out", "w", stdout);

    scanf ("%d\n", &n);
    for (int i = 1; i <= n; i++){
         scanf ("%c %c", &car, &car1);
         if (car == 'A'){
             if (car1 == 'L')
                 Q.push_front(++con);
              else
                 Q.push_back(++con);
         }
          else{
             scanf ("%d", &val);
             if (car1 == 'L')
                 while (val--)
                        Q.pop_front();
              else
                 while (val--)
                        Q.pop_back();
          }
          scanf ("\n");
    }

    while (!Q.empty()){
           printf ("%d\n", Q.front());
           Q.pop_front();
    }

    return 0;
}