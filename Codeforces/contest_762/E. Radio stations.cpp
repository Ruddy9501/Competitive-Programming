/*
2018-03-13 18:45:57
https://codeforces.com/contest/762/problem/E
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
 
using namespace std;
 
int n, m, x, y, z;
long long sol;
 
struct tre{
       int x, y, z;
       bool operator <(const tre &r)const {
       	    return y > r.y;
       } 
};
 
vector <tre> g;
 
 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
 
const int RAN = 1e5 + 5;
ordered_set X[RAN]; //multiset, usar con pair, primer valor es el valor real, el segundo es un contador cualquiera
 
int main(){
 
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
    	 scanf ("%d%d%d", &x, &y, &z);
    	 g.push_back ({x, y, z});
    }
 
    sort (g.begin(), g.end());
 
    for (auto u : g){
    	 int a = max(u.x - u.y, 1);
    	 int b = u.x + u.y + 1;
    	// printf ("%d %d %d ---- %d %d\n", u.x, u.y, u.z, a, b);
    	 
    	 for (int i = max(1, u.z-m); i <= u.z+m; i++)
    	 	  sol += 1ll * (X[i].order_of_key(b) - X[i].order_of_key(a));
    	 X[u.z].insert (u.x);	
    }
 
    printf ("%lld\n", sol);
 
	return 0;
}