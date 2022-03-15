/*
S i j c: change the characters in the range [i, j] to the value c
R i j: reverse the substring starting from position i to position j
C i j c: count the number of characters with value c in
        the range [i, j]
testeado en COJ problem 2418
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct item * pitem;
struct item {
       int prior, value, cnt, c[27];
       bool mar;
       bool rev;
       pitem l, r;

       item (){
             prior = rand ();
             value = cnt = 0;
             rev = mar = 0;
             l = r = 0;
             memset (c, 0, sizeof (c));
       }
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
     if (it)
         it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

int c (pitem it, int p){
    return it ? it -> c[p] : 0;
}

void upd_c (pitem it){
     if (it){

         for (int i = 0; i < 27; ++i)
              it -> c[i] = c (it -> l, i) + c (it -> r, i);
         it -> c[it -> value] += 1;
     }
}

void push (pitem it){
     if (it && it->rev){
         it->rev = false;
         swap (it->l, it->r);
         if (it->l) it->l->rev ^= true;
         if (it->r) it->r->rev ^= true;
     }

     if (it && it -> mar){
         it -> mar = false;

         if (it->l) {
             it->l->value = it->value;
             it->l->mar = true;

             memset (it->l->c, 0, sizeof (it->l->c));
             upd_cnt (it->l);
             it->l->c[it->l->value] = it->l->cnt;
         }

         if (it->r){
             it->r->value = it->value;
             it->r->mar = true;

             memset (it->r->c, 0, sizeof (it->r->c));
             upd_cnt (it->r);
             it->r->c[it->r->value] = it->r->cnt;
         }
     }
}

void merge (pitem & t, pitem l, pitem r) {
     push (l);
     push (r);
     if (!l || !r)
          t = l ? l : r;
     else if (l->prior > r->prior)
              merge (l->r, l->r, r), t = l;
           else
              merge (r->l, l, r->l), t = r;
     upd_cnt (t);
     upd_c (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
     if (!t)
     return void( l = r = 0 );
     push (t);
     int cur_key = add + cnt(t->l);
     if (key <= cur_key)
         split (t->l, l, t->l, key, add), r = t;
    else
         split (t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
     upd_cnt (t);
     upd_c (t);
}

void reverse (pitem t, int l, int r) {
     pitem t1, t2, t3;
     split (t, t1, t2, l-1);
     split (t2, t2, t3, r-l+1);
     t2->rev ^= true;
     merge (t, t1, t2);
     merge (t, t, t3);
}

void output (pitem t) {
     if (!t) return;
     push (t);
     output (t->l);
     printf ("%d ", t->value);
     output (t->r);
}

const int MAX = 1e5 + 15;

char a[MAX], car[5];
int p1, p2, q;

pitem root = 0;

int f (char x){
    return x-'a';
}

int main(){

   // srand (time (0));

    scanf ("%s", a);
    int l = strlen (a);
    for (int i = 0; i < l; ++i){
         pitem x = new item();
         x -> value = f (a[i]);
         merge (root, root, x);
    }

    scanf ("%d", &q);
    while (q--){
           scanf ("%s", car);
           pitem x = 0, y = 0;
           if (car[0] == 'C'){
               scanf ("%d %d %s", &p1, &p2, car);
               int id = f (car[0]);
               split (root, root, x, p1-1);
               split (x, x, y, p2-p1+1);

               printf ("%d\n", c (x, id));

               merge (root, root, x);
               merge (root, root, y);
           }
           else
               if (car[0] == 'R'){
                   scanf ("%d %d", &p1, &p2);
                   reverse (root, p1, p2);
               }
                else{
                   scanf ("%d%d%s", &p1, &p2, car);

                   split (root, root, x, p1-1);
                   split (x, x, y, p2-p1+1);

                   x -> value = f (car[0]);
                   x -> mar = true;

                   merge (root, root, x);
                   merge (root, root, y);
                }

         //output(root);printf ("\n----------\n");
    }

    return 0;
}
