#include <bits/stdc++.h>
using namespace std;

int n, p2, p1, q;
/*
RANGE Min-Max QUERING
testeado en https://www.spoj.com/problems/RMQSQ/
*/
const int MAX = 1e5 + 5;//tamanno maximo

namespace RMQ{

       int mat[MAX][20];
       int l[MAX];
       int n;

       void build (vector <int> &v){

            n = (int)v.size();
            for (int i = 1; i <= n; ++i)
                 l[i] = log2 (i);

            for (int i = 0; i < n; ++i)
                 mat[i+1][0] = v[i];

            int p = n, a;
            for (int i = 1; i <= l[n]; ++i){
                 a = 1 << (i-1);
                 p -= a;
                 for (int j = 1; j <= p; ++j)
                      mat[j][i] = min(mat[j][i-1], mat[j+a][i-1]);
            }
       }

       int find (int p1 , int p2){
           if (p1 > p2) swap (p1, p2);
           int c = l[p2-p1];
           return min (mat[p1][c], mat[p2-(1<<c)+1][c]);
       }
};

int main(){
    scanf("%d", &n);
    vector <int> v;
    for(int i = 1; i <= n; i++){
        int x;scanf("%d", &x);
        v.push_back (x);
    }

    RMQ::build(v);

    scanf ("%d", &q);
    while (q--){
           scanf ("%d %d", &p1, &p2);p1++, p2++;
           printf ("%d\n", RMQ::find (p1, p2));
    }

    return 0;
 }
