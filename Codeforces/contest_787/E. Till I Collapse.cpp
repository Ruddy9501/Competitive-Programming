/*
2017-04-04 19:40:43
https://codeforces.com/contest/787/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int RAN = 1e5 + 5;
 
int n, a, pos = 1, P[RAN];
int root[RAN], S[RAN];
 
struct par{
       int val, id;
       par () {}
       par (int val, int id) : val(val), id(id) {}
       bool operator <(const par &R) const{
       	    return  val < R.val;
       }
}A[RAN];
 
 
struct node {
	int sum, left, right;
 
	node(int sum = 0, int left = 0, int right = 0) : sum(sum), left(left), right(right) {}
};
 
node null;
vector <node> stree;
 
int build(int st, int nd) {
	if(st == nd) {
		stree.push_back(null);
		return (int) stree.size() - 1;
	}
 
	int mid = (st + nd) >> 1;
 
	int left = build(st, mid);
	int right = build(mid + 1, nd);
 
	stree.push_back(node(0, left, right));
	return (int) stree.size() - 1;
}
 
int insert(int x, int st, int nd, int p) {
	if(st > p || nd < p)
		return x;
 
	if(st == nd) {
		stree.push_back(node(1, 0, 0));
		return (int) stree.size() - 1;
	}
 
	int mid = (st + nd) >> 1;
 
	int left = insert(stree[x].left, st, mid, p);
	int right = insert(stree[x].right, mid + 1, nd, p);
 
	stree.push_back(node(stree[left].sum + stree[right].sum, left, right));
	return (int) stree.size() - 1;
}
 
int query(int x, int st, int nd, int k) {
	if(st == nd)
		return st;
 
	int mid = (st + nd) >> 1;
	int l = stree[x].left;
	int r = stree[x].right;
 
	if(k < stree[l].sum)
		return query(l, st, mid, k);
 
	return query(r, mid + 1, nd, k - stree[l].sum);
}
 
int can = 0;
 
int main (){
 
    scanf ("%d", &n); 
    for (int i = 1; i <= n; i++){
    	 scanf ("%d", &a);
    	 A[i] = par(P[a], i);
    	 P[a] = i;
    }
    
    sort (A+1, A+n+1);
    
    root[can++] = build(1, n+1);
    for (int i = 1; i <= n; i++){
         //printf ("%d ", A[i].val);
         while (A[pos].val < i && pos <= n) {
         	    root[can] = insert(root[can-1], 1, n+1, A[pos++].id);
                can++;
         }
 
         S[i] = root[can-1];
    }printf("\n");
    
    for (int i = 1; i <= n; i++){
         //printf ("i : %d\n", i);
         int sol = 0, pos = 1;
         while (pos <= n){
         	    sol++;
         	    pos = query(S[pos], 1, n+1, pos+i-1);
         	   // printf ("%d ", pos);
         }//printf ("\n");
         //break;
         if (i == n) printf ("%d\n", sol);
          else printf ("%d ", sol); 
    } 
 
	return 0;
}