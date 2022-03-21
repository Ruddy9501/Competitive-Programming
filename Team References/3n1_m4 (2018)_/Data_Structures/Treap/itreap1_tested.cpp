// Implicit indexes Cartesian Tree 
// testeado en https://www.spoj.com/problems/GSS6/
/*
  Given a sequence A of N (N <= 100000) integers,
  you have to apply Q (Q <= 100000) operations:
  Insert, delete, replace an element, find the
  maximum contiguous(non empty) sum in a given interval.
*/
#include <bits/stdc++.h>

using namespace std;

typedef struct item * pitem;
struct item {
  int prior;
  int pre, suf, msum;
  int value, tot;
  int cnt, rev;
  pitem l, r;

  item (){
    prior = rand ();
    cnt = 1;
    value = tot = pre = suf;
    msum = -1<<30;
    rev = 0;
    l = r = 0;
  }
};

int cnt (pitem it) {return it ? it->cnt : 0;}
void upd_cnt (pitem it) {if (it)it->cnt = cnt(it->l) + cnt(it->r) + 1;}
int tot (pitem it) {return it ? it->tot : 0;}

void upd_tot (pitem it) {
  if (it)
    it->tot = tot(it->l) + tot(it->r) + it -> value;
}

int suf (pitem it){return it ? it -> suf : 0;}
int pre (pitem it){return it ? it -> pre : 0;}
int msum (pitem it) {return it ? it->msum : -1<<30;}

void upd_msum (pitem it) {
  if (it)
    it->msum = max ({msum(it->l), msum (it->r),
      suf (it -> l) + it -> value + pre (it -> r)});
}

void upd_pre (pitem it){
  if (it)
    it -> pre = max (pre (it -> l),
      tot (it -> l) + it -> value + pre (it -> r)); 
}

void upd_suf (pitem it){
  if (it)
    it -> suf = max (suf (it -> r),
      tot (it -> r) + it -> value + suf (it -> l));
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
  upd_cnt (t); upd_tot (t);
  upd_pre (t); upd_suf (t);
  upd_msum (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t) return void( l = r = 0 );
  push (t);
  int cur_key = add + cnt(t->l);
  if (key <= cur_key) split (t->l, l, t->l, key, add), r = t;
  else split (t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
  upd_cnt (t); upd_tot (t);
  upd_pre (t); upd_suf (t);
  upd_msum (t);
}

void reverse (pitem t, int l, int r) {
  pitem t1, t2, t3;
  split (t, t1, t2, l); split (t2, t2, t3, r-l+1);
  t2->rev ^= true;
  merge (t, t1, t2); merge (t, t, t3);
}

void output (pitem t) {
  if (!t) return;
  push (t);
  output (t->l);
  printf ("%c", t->value);
  output (t->r);
}

int main(){
  srand(time(0));
  ios_base::sync_with_stdio (0);
  cin.tie (0);
  cout.tie (0);

  pitem root = 0;    
  int n; cin >> n;
  for (int i = 0; i < n; ++i){
    int v; cin >> v;
    pitem x = new item ();
    x -> value = v;
    x -> msum = v;
    x -> pre =  x -> suf = max (0, v);
    merge (root, root, x);
  }

  cin >> n;
  int x, y;
  pitem tem = 0, x1;
  pitem b = 0;               
  while (n--){
    char s;
    cin >> s;
    switch (s){
      case 'I':
        cin >> x >> y;
        tem = 0;
        split (root, root, tem, x-1);

        x1 = new item ();
        x1 -> value = y;
        x1 -> msum = y;
        x1 -> pre =  x1 -> suf = max (0, y);

        merge (root, root, x1);
        merge (root, root, tem);

        break ;   
      case 'D':
        cin >> x;
        tem = 0, b = 0;
        split (root, root, tem, x-1);
        split (tem, b, tem, 1);
        merge (root, root, tem);
        break ;  
      case 'R': 
        cin >> x >> y; 
        tem = 0, b = 0;

        x1 = new item ();
        x1 -> value = y;
        x1 -> msum = y;
        x1 -> pre =  x1 -> suf = max (0, y);

        split (root, root, tem, x-1);
        merge (root, root, x1);

        split (tem, b, tem, 1);
        merge (root, root, tem);
        break ;   
      case 'Q': 
        cin >> x >> y;
        tem = 0, b = 0;
        split (root, root, tem, x-1);
        split (tem, tem, b, y-x+1);

        cout << msum (tem) << "\n";
        merge (root, root, tem);
        merge (root, root, b);

        break ;   
    }   
  }
  return 0;
}
