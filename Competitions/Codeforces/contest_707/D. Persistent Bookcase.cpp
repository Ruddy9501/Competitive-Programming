/*
2018-10-16 03:52:11
https://codeforces.com/contest/707/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
struct node{
       int v, l, r, pt;
       node (int v, int l, int r, int pt) : v (v), l (l), r (r), pt (pt) {}
};
 
const int MAX = 1e5 + 5;
 
node null (0, 0, 0, 0);
vector <node> St;
vector <bitset <1001> > hoja;
int root[MAX];
int n, m, q, id, x, y;
 
int build (int st, int nd){
 
    if (st == nd){
        hoja.push_back (bitset <1001> ());
        int pt = (int) hoja.size () - 1;
        St.push_back ({0, 0, 0, pt});
        return (int) St.size () - 1;
    }
 
    int piv = (st + nd) >> 1;
    int l = build (st, piv);
    int r = build (piv+1, nd);
 
    St.push_back ({0, l, r, 0});
    return (int) St.size () - 1;
}
 
int update (int x, int st, int nd, int pos){
 
    if (st > pos || nd < pos) return x;
 
    if (st == nd){
        hoja.push_back (hoja[St[x].pt]);
        int pt = (int) hoja.size () - 1;
 
        if (id == 1)
            hoja[pt].set (y);
 
        if (id == 2)
            hoja[pt].reset (y);
 
        if (id == 3)
            for (int i = 1; i <= m; ++i)
                 hoja[pt].flip (i);
 
        int v = hoja[pt].count ();
 
        St.push_back ({v, 0, 0, pt});
        return (int) St.size () - 1;
    }
 
    int piv = (st+nd)>>1;
    int l = update (St[x].l, st, piv, pos);
    int r = update (St[x].r, piv+1, nd, pos);
 
    St.push_back ({St[l].v+St[r].v, l, r, 0});
    return (int) St.size () - 1;
}
 
int main (){
 
    scanf ("%d%d%d", &n, &m, &q);
    St.push_back (null);
    root[0] = build (1, n);
    for (int i = 1; i <= q; ++i){
         scanf ("%d\n", &id);
 
         root[i] = root[i-1];
         if (id == 1 || id == 2){
             scanf ("%d %d", &x, &y);
             root[i] = update (root[i], 1, n, x);
         }
 
         if (id == 3){
             scanf ("%d", &x);
             root[i] = update (root[i], 1, n, x);
         }
 
         if (id == 4){
             scanf ("%d", &x);
             root[i] = root[x];
         }
 
         printf ("%d\n", St[root[i]].v);
    }
 
    return 0;
}