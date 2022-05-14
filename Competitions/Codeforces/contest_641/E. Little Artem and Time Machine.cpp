/*
2019-01-30 17:30:16
https://codeforces.com/contest/668/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5 + 5;
int n, a[MAX], t[MAX], x[MAX], s[MAX], b[MAX];
vector <int> v, v2, sol;
 
struct tre{
       int a, t, id;
};
 
vector <tre> v1[MAX];
 
int query (int x){
     int sum = 0;
     for (int i = x; i > 0; i -= (i & -i))
          sum += b[i];
      return sum;
}
 
void update (int x, int s){
     for (int i = x; i < MAX; i += (i & -i))
          b[i] += s;
}
 
int main (){
 
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i){
         scanf ("%d%d%d", &a[i], &t[i], &x[i]);
         v.push_back (x[i]);
         v2.push_back (t[i]);
    }
 
    sort (v.begin (), v.end ());
    auto it = unique (v.begin (), v.end ());
    v.erase (it, v.end ());
 
    sort (v2.begin (), v2.end ());
    auto it1 = unique (v2.begin (), v2.end ());
    v2.erase (it1, v2.end ());
 
    for (int i = 1; i <= n; ++i){
         int p = upper_bound (v.begin (), v.end (), x[i]) - v.begin ();
         t[i] = upper_bound (v2.begin (), v2.end (), t[i]) - v2.begin ();
         v1[p].push_back ((tre){a[i], t[i], i});
    }
 
    for (int i = 1; i < MAX; ++i){
 
         for (auto u : v1[i]){
              if (u.a == 3)
                  s[u.id] = query (u.t);
              else
                 if (u.a == 1)
                    update (u.t, 1);
                  else update (u.t, -1);
         }
 
         for (auto u : v1[i])
              if (u.a == 1) update (u.t, -1);
               else
                  if (u.a == 2) update (u.t, 1);
    }
 
    for (int i = 1; i <= n; ++i){
         if (a[i] == 3) sol.push_back (s[i]);
    }
 
    int l = (int)sol.size ();
    for (int i = 0; i < l; ++i){
         printf ("%d", sol[i]);
         printf ("\n");
    }
 
    return 0;
}