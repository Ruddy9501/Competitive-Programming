/*
Ruddy Guerrero Alvarez
12mo
Villa Clara -> Caibarien
NACIONAL/2009
AD-HOD
*/
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define RAN 100005
using namespace std;
typedef pair<int, int>par;

int f, c, ult, ini, r, r1, sol = 4, ant, fin, ant1, fin1;
char A[RAN];
bool mar;
stack <par> I, F;

int main(){

    freopen ("IMAGEN.in", "r", stdin);
    freopen ("IMAGEN.out", "w", stdout);

    scanf ("%d %d\n", &f, &c);

    for (int i = 1 ; i <= f; i++){
         for (int j = 0; j < c; j++)
              scanf ("%c", &A[j]);
         scanf ("\n");
         mar = false;
         for (int j = 0; j < c; j++)
              if (A[j] == '1'){
                  ult = j;
                  if (mar == false){
                      ini = j;
                      mar = true;
                  }
              }
	     if (ini == ult && ult == 0)
             continue;
         while (!I.empty() && ini < I.top().second){
                //r--;
                I.pop();
         }
         I.push (par(i, ini));
         //r++;
         while (!F.empty() && ult > F.top().second){
                //r1--;
                F.pop();
         }
         F.push (par(i, ult));
         r1++;
         fill (A , A + c + 1, 0);
    }

    if (I.empty()){
        printf ("0");
        return 0;
    }
    sol += (abs (I.top().first - F.top().first)+
            abs (I.top().second - F.top().second));

    int ant = I.top().first;
    int fin = I.top().second;
    I.pop();
    //r--;
    while (!I.empty()){
           //r--;
           sol += (abs (ant - I.top().first)+
                   abs (fin - I.top().second));
           ant = I.top().first;
           fin = I.top().second;
           I.pop();
    }

    ant1 = F.top().first;
    fin1 = F.top().second;
    F.pop();
    //r1--;
    while (!F.empty()){
           //r1--;
           sol += (abs (ant1 - F.top().first)+
                   abs (fin1 - F.top().second));
           ant1 = F.top().first;
           fin1 = F.top().second;
           F.pop();
    }

    sol += (abs(ant - ant1) + abs(fin - fin1));

    if (sol == 4)
	    sol = 0;

    printf ("%d\n", sol);

    return 0;
}
