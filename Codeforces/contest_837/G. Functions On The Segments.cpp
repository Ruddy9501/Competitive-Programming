/*
2018-10-17 04:57:24
https://codeforces.com/contest/837/problem/G
*/
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int64;
 
const int MAXN = 75000 + 5;
const int N = 2e5 + 1;
const int64 mod = 1e9;
 
int n, m, l, r;
int64 x, last;
 
struct fun{
       int x1, x2;
       int y1, a, b, y2;
}a[MAXN];
 
struct node{
       int64 y1, a;
       int l, r;
       int64 ly1, la;
       node () {}
       node (int64 y1, int64 a, int l, int r, int64 ly1, int64 la)
            : y1 (y1), a (a), l (l), r (r), ly1 (ly1), la (la) {}
};
 
node null (0, 0, 0, 0, 0, 0);
node St[26720000];
int pos;
int root[MAXN];
 
int build (int st, int nd){
 
    if (st == nd){
        St[pos++] = null;
        return pos - 1;
    }
 
    int piv = (st+nd) >> 1;
    int l = build (st, piv);
    int r = build (piv+1, nd);
 
    St[pos++] = {0,0,l,r,0,0};
    return pos - 1;
}
 
void leisy (int x, int st, int nd){
 
     if (!(St[x].ly1 || St[x].la)) return ;
 
     if (st != nd){
 
         St[pos++] = St[St[x].l]; int l = pos - 1;
         St[pos++] = St[St[x].r]; int r = pos - 1;
 
         St[l].ly1 += St[x].ly1;
         St[l].la += St[x].la;
 
         St[r].ly1 += St[x].ly1;
         St[r].la += St[x].la;
 
         St[x].l = l;
         St[x].r = r;
     }
 
     St[x].y1 += St[x].ly1 * (nd-st+1);
     St[x].a += St[x].la * (nd-st+1);
 
     St[x].ly1 = St[x].la = 0;
}
 
int update (int x, int st, int nd, int ini, int fin, int id, int i){
 
    leisy (x, st, nd);
 
    if (st > fin || nd < ini) return x;
 
    if (st >= ini && nd <= fin){
 
        int64 ly1 = St[x].ly1;
        int64 la = St[x].la;
 
        if (id == 1) ly1 += a[i].y1;
        if (id == 2) la += a[i].a, ly1 += a[i].b;
        if (id == 3) ly1 += a[i].y2;
 
        St[pos++] =  {St[x].y1, St[x].a, St[x].l, St[x].r, ly1, la};
        x = pos - 1;
        leisy (x, st, nd);
 
        return x;
    }
 
    int piv = (st+nd) >> 1;
    int l = update (St[x].l, st, piv, ini, fin, id, i);
    int r = update (St[x].r, piv+1, nd, ini, fin, id, i);
 
    int64 y1 = St[l].y1 + St[r].y1;
    int64 a = St[l].a + St[r].a;
 
    St[pos++] = {y1, a, l, r, 0, 0};
    return pos - 1;
}
 
int64 A, B;
 
void query (int x, int st, int nd, int pos1, int id){
 
    //leisy (x, st, nd);
 
    if (st > pos1 || nd < pos1) return ;
 
    A += St[x].la*id;
    B += St[x].ly1*id;
 
    if (st == nd){
        A += St[x].a*id;
        B += St[x].y1*id;
        return ;
    }
 
    int piv = (st+nd) >> 1;
    if (pos1 <= piv)  query (St[x].l, st, piv, pos1, id);
     else query (St[x].r, piv+1, nd, pos1, id);
}
 
int main(){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i){
         scanf ("%d%d%d%d%d%d", &a[i].x1, &a[i].x2, &a[i].y1, &a[i].a, &a[i].b, &a[i].y2);
    }
    St[pos++]  = null;
    root[n] = build (0, N);
    for (int i = n; i >= 1; --i){
         root[i] = root[i+1];
         root[i] = update (root[i], 0, N, 0, a[i].x1, 1, i);
         root[i] = update (root[i], 0, N, a[i].x1+1, a[i].x2, 2, i);
         root[i] = update (root[i], 0, N, a[i].x2+1, N, 3, i);
    }
 
    scanf ("%d", &m);
    for (int i = 1; i <= m; ++i){
         scanf ("%d %d %lld", &l, &r, &x);
         x = min (1ll * N, (x % mod + last) % mod);
 
         A = B =0;
         query (root[l], 0, N, x, 1);
         query (root[r+1], 0, N, x, -1);
 
         printf ("%lld\n", last = A*x+B);
    }
 
    return 0;
}