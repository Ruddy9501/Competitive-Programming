/* Treap persistente
 * testeado https://www.codechef.com/status/GENETICS
 * 
 * >> cross operation - they take DNA1 and DNA2 and
 *  numbers k1 and k2. Then two new DNAs are
 *  created: DNA3 = DNA1[1..k1]+DNA2[k2+1..] and
 *  DNA4 = DNA2[1..k2]+DNA1[k1+1..].
 * >> mutate operation - they take a DNA, number k
 *  and one of the bases. Then they replace the
 *  base in position k in DNA with that base.
 * >> count operation - they take DNA and numbers k1
 *  and k2 (k1 <= k2). This operation should return
 *  the number of A, G, T, C bases in DNA[k1..k2].
 */
#include <bits/stdc++.h>
using namespace std;

char a[300005];

typedef struct item * pitem;
struct item {

       int prior;
       int sum[5];
       int cnt;
       int id;
       pitem l, r;
       item (){
             prior = rand ();
             cnt = 1;
             id = 0;
             memset (sum, 0, sizeof (sum));
             l = r = 0;
       }
};

int f (char car){
    if (car == 'A') return 0;
    if (car == 'G') return 1;
    if (car == 'T') return 2;
    return 3;
}

int cnt (pitem it) {
 return it ? it->cnt : 0;
}

int sum (pitem it, int k) {
 return it ? it->sum[k] : 0;
}

void upd_cnt (pitem it) {
 if (it)
 it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void upd_sum (pitem it){
     if (it){
         for (int i = 0; i < 4; ++i)
              it -> sum[i] = sum (it -> l, i) + sum (it -> r, i);
         it -> sum[it -> id]++;
     }
}

void merge (pitem & t, pitem l, pitem r) {

     if (!l || !r)
         t = l ? l : r;
     else
        if (l->prior > r->prior)
            merge (l->r, l->r, r), t = l;
         else
            merge (r->l, l, r->l), t = r;
     upd_cnt (t);
     upd_sum (t);
}

pitem clone (pitem x){

      pitem y = new item ();
      if (x -> r)y -> r = x -> r;
      if (x -> l)y -> l = x -> l;

      y -> cnt = x -> cnt;
      y -> id = x -> id;
      y -> prior = x -> prior;
      for (int i = 0; i < 4; ++i)
           y -> sum[i] = x -> sum[i];
      return y;
}

void splitp (pitem t, pitem & l, pitem & r, int key, int add = 0) {

     if (!t)
         return void( l = r = 0 );

     t = clone (t);

     int cur_key = add + cnt(t->l);
     if (key <= cur_key)
         splitp (t->l, l, t->l, key, add), r = t;
      else
         splitp (t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;

     upd_cnt (t);
     upd_sum (t);
}

void print (pitem t){
     if (t){
         print (t -> l);
         if (t -> id == 0) printf ("A");
         if (t -> id == 1) printf ("G");
         if (t -> id == 2) printf ("T");
         if (t -> id == 3) printf ("C");
         print (t -> r);
     }
}

int main(){

    srand(time(0));

    int n;
    cin >> n; vector <pitem> v;
    for (int i = 0; i < n; ++i){
         cin >> a;
         int l = strlen (a);
         pitem root = 0;
         for (int j = 0; j < l; ++j){
              pitem tem = new item();
              tem -> sum[f(a[j])]++;
              tem -> id = f (a[j]);
              merge (root, root, tem);
         }

         v.push_back (root);
    }

    int q;
    cin >> q;
    while (q--){
           string s; int id1, id2, k1, k2; char car;
           cin >> s;
           if (s == "COUNT"){
               cin >> id1 >> k1 >> k2; id1--;
               pitem x = 0, y = 0;
               splitp (v[id1], v[id1], x, k1-1);
               splitp (x, x, y, k2-k1+1);

               for (int i = 0; i < 4; ++i){
                    cout << x -> sum[i];
                    if (i == 3) cout << "\n";
                     else cout << " ";
               }

               merge (v[id1], v[id1], x);
               merge (v[id1], v[id1], y);
           }
            else
               if (s == "MUTATE"){
                   cin >> id1 >> k1 >> car; id1--;

                   pitem x = 0, y = 0;
                   splitp (v[id1], v[id1], x, k1-1);
                   splitp (x, x, y, 1);

                   x -> id = f (car);

                   merge (v[id1], v[id1], x);
                   merge (v[id1], v[id1], y);
               }
               else{
                   cin >> id1 >> id2 >> k1 >> k2; id1--; id2--;

                   pitem x1 = 0, y1 = 0, x2 = 0, y2 = 0, root1 = 0,
                    root2 = 0;

                   splitp (v[id1], x1, y1, k1);
                   splitp (v[id2], x2, y2, k2);

                   merge (root1, x1, y2);
                   merge (root2, x2, y1);

                  // print (x1); printf("\n"); print (y1);
                  // print (x2); printf("\n"); print (y2);

                   v.push_back (root1);
                   v.push_back (root2);
               }

               //for (auto it : v){print (it); printf ("\n");}
               // printf ("--------------\n");
    }

    return 0;
}
/*
2
CTCGC
TGCGG
5
MUTATE 1 2 A
COUNT 2 2 4
MUTATE 2 1 G
CROSS 2 1 1 5
COUNT 4 3 6
*/
