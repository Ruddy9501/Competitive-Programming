/*
Ruddy Guerrero Alvarez
PSN 2010 Prueba final #10
Pueblos y Caminos/road
*/
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>

#define RAN 5010
#define oo 1 << 30
using namespace std;

typedef pair<long long, long long>par;

vector <par> V[RAN];
priority_queue <par, vector <par>, greater<par> >Q;

long long COM[RAN], CF[RAN], CI[RAN], sol = oo;
long long nod, newn, la, cos, newc, a, b, c, I, F,  nd, nc, K;

int main(){

    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);

    scanf ("%lld %lld %lld", &nd, &nc, &K);
    scanf ("%lld %lld", &I, &F);
    fill (COM + 1, COM + nd + 1, oo);
    fill (CI + 1, CI + nd + 1, oo);
    fill (CF + 1, CF + nd + 1, oo);
    for (int i = 1; i <= K; i++){
         scanf ("%lld %lld", &a, &b);
         COM[a] = b;
    }

    for (int i = 1; i <= nc; i++){
         scanf ("%lld %lld %lld", &a, &b, &c);
         V[a].push_back(par(b, c));
         V[b].push_back(par(a, c));
    }

    Q.push(par(0, I));
    CI[I] = 0;
    while (!Q.empty()){
           nod = Q.top().second;
           cos = Q.top().first;
           Q.pop();
           la = V[nod].size();
           for (int i = 0; i < la; i++){
                newn = V[nod][i].first;
                newc = V[nod][i].second + cos;
                if (CI[newn] > newc){
                    CI[newn] = newc;
                    Q.push(par(newc, newn));
                }
           }
    }

    Q.push(par(0, F));
    CF[F] = 0;
    while (!Q.empty()){
           nod = Q.top().second;
           cos = Q.top().first;
           Q.pop();
           la = V[nod].size();
           for (int i = 0; i < la; i++){
                newn = V[nod][i].first;
                newc = V[nod][i].second + cos;
                if (CF[newn] > newc){
                    CF[newn] = newc;
                    Q.push(par(newc, newn));
                }
           }
    }

    for (int i = 1; i <= nd; i++)
         if (sol > CI[i]+CF[i]+COM[i])
             sol = CI[i]+CF[i]+COM[i];

    printf ("%lld\n", sol);

    return 0;
}
