/*
Ruddy Guerrero Alvarez
Villa Clara -> Caibarien
USACO\Problems\2010-11\November\Problems\Silver
Leche Chocolatada\ chocmilk
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>

#define RAN 100010
using namespace std;

int n, a, b, c, A[RAN], B[RAN], T[RAN], nod, newn;
bool M[RAN];

vector <int>V[RAN];
priority_queue<int, vector<int>, greater<int> >S, Q;

int main(){

    freopen ("chocmilk.in", "r", stdin);
    freopen ("chocmilk.out", "w", stdout);

    scanf ("%d", &n);
    for (int i = 1; i < n; i++){
         scanf ("%d %d", &a, &b);
         V[a].push_back(b);
         B[b]++;
         A[a]++;
    }

    for (int i = 1; i <= n; i++)
         if (!B[i])
             Q.push(i), c++, T[i] = 1;

    while (!Q.empty()){
           nod = Q.top();
           Q.pop();
           for (int i = 0; i < V[nod].size(); i++){
           newn = V[nod][i];
           T[newn] += (T[nod] - A[nod]+1);
           if (!M[newn]){
               Q.push(newn);
               M[newn] = 1;
           }
           if (T[newn] == c)
               S.push(newn);
           }
    }

    while (!S.empty()){
           printf ("%d\n", S.top());
           S.pop();
    }

    return 0;
}
