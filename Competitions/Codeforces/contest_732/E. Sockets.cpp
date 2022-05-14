/*
2016-10-17 22:29:02
https://codeforces.com/contest/732/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
int n, m, A[200005], B[200005];
int sol1, sol2, a, con, S1[200005], S2[200005];
map <int, int> M;
 
map <int, vector<int> >M1;
 
struct par{
       int p, v;
       bool operator <(const par &R)const{
            return v < R.v;
       }
}C[200005];
 
int main(){
 
 
    //cin.tie(0);
 
    //cin >> n >> m;
    scanf ("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
         scanf ("%d", &A[i]);
         M[A[i]]++;
         M1[A[i]].push_back(i);
    }
 
    for (int i = 1; i <= m; i++){
         scanf ("%d", &C[i].v);//cin >> C[i].v;
         C[i].p = i;
    }
 
    sort (C+1,C+m+1);
 
    for (int i = 1; i <= m; i++){
         a = C[i].v;
         int p = C[i].p;
         con = 0;
         do{
            int r = M[a]--;
            if (r != NULL && r > 0){
                sol2 += con;
                sol1++;
                S1[p] = con;
                S2[M1[a][r-1]] = p;
                break;
            }
            con++;
            if (a==1) break;
            a = (a+1)/2;
         }while (1);
    }
 
    cout << sol1 << " " << sol2 <<endl;
    cout << S1[1];
    for (int i = 2; i <= m; i++)
         cout << " " << S1[i];
    cout << endl;
 
    cout << S2[1];
    for (int i = 2; i <= n; i++)
         cout << " " << S2[i];
    cout << endl;
 
    return 0;
}