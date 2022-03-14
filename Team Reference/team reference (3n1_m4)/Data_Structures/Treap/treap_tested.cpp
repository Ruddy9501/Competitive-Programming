// Treap (Explicit)
// testeado https://www.spoj.com/problems/ORDERSET/
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
  int val,prior,size;
  struct node *l,*r;
  node(int val,int prior,int size=1)
    : val(val), prior(prior), size(size), l(nullptr), r(nullptr){}
}node;
typedef node* pnode;

pnode root=nullptr;

int sz(pnode t){return t?t->size:0;}
void upd_sz(pnode t){if(t) t->size = sz(t->l)+1+sz(t->r);}

void split(pnode t,pnode &l,pnode &r,int key){
  if(!t) l=r=NULL;
  else if(t->val<=key) split(t->r,t->r,r,key),l=t; //elem=key is in l
  else split(t->l,l,t->l,key),r=t;    
  upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r){
  if(!l || !r) t=l?l:r;
  else if(l->prior > r->prior)merge(l->r,l->r,r),t=l;
  else merge(r->l,l,r->l),t=r;
  upd_sz(t);
}
void insert(pnode &t,pnode it){
  if(!t) t=it;
  else if(it->prior>t->prior) split(t,it->l,it->r,it->val),t=it;
  else insert(t->val<=it->val?t->r:t->l,it);
  upd_sz(t);
}
void erase(pnode &t,int key){
  if(!t)return;
  else if(t->val==key){pnode temp=t;merge(t,t->l,t->r);free(temp);}    
  else erase(t->val<key?t->r:t->l,key);
  upd_sz(t);
}
pnode init(int val){
  pnode ret = (pnode)malloc(sizeof(node));
  ret->val=val;ret->size=1;ret->prior=rand();ret->l=ret->r=NULL;
  return ret;
}

/* Cuenta cantidad de elementos con valor <= key
 */
int count(pnode &r, int key)
{
  //~ pnode x=nullptr;
  //~ split(root, root, x, key-1);
  //~ int rs = sz(root);
  //~ merge(root,root,x);
  //~ return rs;
  if(r == nullptr) return 0;
  if(r -> val <= key) return sz(r->l) + 1 + count(r->r,key);
  return count(r->l,key);
}
/* Encuentra el kth elemento
 */
int kth(pnode &r, int k, int des=0)
{
  int ndes = des + sz(r->l) + 1;
  if(ndes == k) return r->val;
  if(ndes < k) return kth(r->r, k,ndes);
  else return kth(r->l, k, des);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  
  srand(time(nullptr));
   
  int q;cin >> q;
  while(q--)
  {
    char op;
    int x;
    cin >> op >> x;
    switch(op)
    {
      case 'I':
        erase(root, x);
        insert(root,init(x));
        break;
      case 'D':erase(root,x);break;
      case 'C':cout << count(root,x-1) << '\n';break;
      case 'K':
        if(sz(root) < x) cout << "invalid\n";
        else cout << kth(root,x) << '\n';
        break;
    }
  }
  
  return 0;
}
