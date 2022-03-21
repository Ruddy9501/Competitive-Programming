// Implicit indexes Cartesian tree
// testeado (Robotic Sort) https://www.spoj.com/problems/CERC07S/
#include <bits/stdc++.h>
using namespace std;

typedef struct item * pitem;
struct item
{
 int prior, value, mi, can, pos, mpos, cnt;
 bool rev;
 pitem l, r;

 item (){
   prior = rand ();cnt = 1;
   value = 0;mi = INT_MAX;pos = INT_MAX;
   mpos = INT_MAX;
   can = rev = 0;
   l = r = 0;
 }
};

int cnt (pitem it) {return it ? it->cnt : 0;}
void upd_cnt (pitem it) {if (it) it->cnt = cnt(it->l) + cnt(it->r) + 1;}
int mi (pitem it){return it ? it -> mi : INT_MAX; }

int can (pitem it){
  if (!it) return 0;
  if (it -> rev == 0) return it -> can;
  else return   cnt (it) - it -> can + 1;      
}

int mpos (pitem it){return it ? it -> mpos : INT_MAX;}

void upd_mi (pitem it){
  if (it){
    int m1 = mi (it -> l), m2 = mi (it -> r);
    int p1 = mpos (it -> l), p2 = mpos (it -> r);
    int c1 = can (it -> l), c2 = can (it -> r);
   
    int v = it -> value;
    int p = it -> pos;
    
    int menor = min ({v, m1, m2});
    int pos = 1<<30, can = 0;
    
    if (m1 == menor && pos > p1){
      can = c1;
      pos = p1;
    }
    
    if (m2 == menor && pos > p2){
      can =  c2 + 1 + cnt (it -> l);
      pos = p2;
    }
        
    if (v == menor && pos > p){
      can = 1 + cnt (it -> l);
      pos = p;
    }
    
    it -> mpos = pos;
    it -> mi = menor;
    it -> can = can;
  }
}

void push (pitem it) {
  if (it && it->rev) {
    it->rev = false;
    swap (it->l, it->r);
    if (it->l) it->l->rev ^= true;
    if (it->r) it->r->rev ^= true;
  }
}

void merge (pitem & t, pitem l, pitem r) {
  push (l); push (r);
  if (!l || !r) t = l ? l : r;
  else if (l->prior > r->prior) merge (l->r, l->r, r), t = l;
  else merge (r->l, l, r->l), t = r;
  upd_cnt (t); upd_mi (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t) return void( l = r = 0 );
  push (t);
  int cur_key = add + cnt(t->l);
  if (key <= cur_key) split (t->l, l, t->l, key, add), r = t;
  else split (t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
  upd_cnt (t); upd_mi (t);
}

void reverse (pitem t, int l, int r) {
  pitem t1, t2, t3;
  split (t, t1, t2, l); split (t2, t2, t3, r-l+1);
  t2->rev ^= true;
  merge (t, t1, t2); merge (t, t, t3);
}

void erase (pitem it){     
  if (it){
    erase (it -> l);
    erase (it -> r);
    delete (it); 
  }
}

void output (pitem t) {
  if (!t) return;
  push (t);
  output (t->l);
  printf ("%d %d %d mpos: %d mi: %d can: %d\n",
  t->value, t -> pos, t -> prior, t -> mpos, t -> mi, t -> can);
  output (t->r);
}

int n, x;

int main(){
  srand(time(0));
  while (scanf ("%d", &n) && n){
    pitem root = 0;
    for (int i = 0; i < n; ++i){
      scanf ("%d", &x);
      pitem tem = new item ();
      tem -> value = x;
      tem -> mi = x;
      tem -> can = 1;
      tem -> pos = i+1;
      tem -> mpos = i+1;
      merge (root, root, tem); 
    }

    int cant = 0;
    while (n--){
      int p = can (root);

      printf ("%d", p+cant);
      if (n == 0) printf ("\n");
      else printf (" ");

      pitem  x = 0;
      reverse (root, 0, p-1); 
      split (root, x, root, 1);

      cant++;
      erase (x);
    }
    erase (root);
  }
  return 0;
}
