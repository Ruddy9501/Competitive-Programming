/*
2017-08-14 19:33:17
https://codeforces.com/contest/839/problem/C
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 1e5 + 5;
 
int n, a, b, L[RAN];
double sol, p[RAN];
bool M[RAN];
vector <int> v[RAN];
 
void dfs (int nod){
     M[nod] = true;
     int l = (int)v[nod].size();
     int d = l;
     bool flag = true;
     if (nod != 1) d--;
     for (int i = 0; i < l; i++){
 
          int newn = v[nod][i];
 
          if (M[newn]) continue;
 
          flag = false;
          p[newn] = p[nod]*(1.0/(d));
          L[newn] = L[nod] + 1;
          dfs (newn);
     }
 
     if (flag)
         sol += (p[nod]*L[nod]);
 
     //printf ("%d %d %f\n", nod, L[nod], p[nod]);
}
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 0; i < n-1; i++){
         scanf ("%d %d", &a, &b);
         v[a].push_back(b);
         v[b].push_back(a);
    }
 
    p[1] = 1.0;
    M[1] = true;
    dfs (1);
 
    printf ("%.10f\n", sol);
 
    return 0;
}