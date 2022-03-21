// testeado coj - 1554, 3358,
// https://codeforces.com/contest/1017/problem/E
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
struct R2vec
{
  int x,y;
  R2vec(){}
  R2vec(int x,int y):x(x),y(y){}
  inline R2vec operator+ (const R2vec &w){return R2vec(x+w.x,y+w.y);}
  inline R2vec operator- (const R2vec &w){return R2vec(x-w.x,y-w.y);}
  inline R2vec operator- (){return R2vec(-x,-y);}
  inline ll operator* (const R2vec &w){return (ll)x*w.x + (ll)y*w.y;} // dot
  inline ll operator% (const R2vec &w){return (ll)x*w.y - (ll)y*w.x;} // cross
  inline ll operator~ (){return (ll)x*x + (ll)y*y;} // norm^2
  inline bool operator< (const R2vec &w)const{return x!=w.x?x<w.x:y<w.y;}
  inline bool operator== (const R2vec &w){return x==w.x&&y==w.y;}
  inline bool operator!= (const R2vec &w){return x!=w.x||y!=w.y;}
};
inline ostream &operator<< (ostream &out,const R2vec &w)
{return out<<'['<<w.x<<','<<w.y<<']';}

typedef pair<ll,ll> pll;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

struct ConvexHull
{
  vector<R2vec> hull;
  ConvexHull(){}
  ConvexHull(vector<R2vec> cloud)
  {
    sort(all(cloud)); vector<R2vec> up,down;
    for(auto &w: cloud)
    {
      while(sz(up) > 1 && (up.back()-up[sz(up)-2])%(w-up.back())>=0)
        up.pop_back();
      up.pb(w);
      while(sz(down) > 1 && (down.back()-down[sz(down)-2])%(w-down.back())<=0)
        down.pop_back();
      down.pb(w);
    }
    hull = up;
    for(int i=sz(down)-2;i;--i)hull.pb(down[i]);
    //~ cout << "UPPER:\n";for(auto &w: up)cout << w;cout << endl;
    //~ cout << "LOWER:\n";for(auto &w: down)cout << w;cout << endl;
    //~ cout << "Convex Hull\n";for(auto &w: hull)cout << w;cout << endl;
  }
  #define NEXT(i) (i+1<sz(hull)?i+1:0)
  #define PREV(i) (i?i-1:sz(hull)-1)
  vector<pll> hash() // util para comparar dos convex hulls
  { // testeada en https://codeforces.com/contest/1017/problem/E
    vector<pll> res(sz(hull));
    for(int i=0;i<sz(hull);++i)
      res[i]={~(hull[i]-hull[PREV(i)]),
          (hull[PREV(i)]-hull[i])*(hull[NEXT(i)]-hull[i])};
    return res;
  }
};

int main()
{
  vector<R2vec> p;
  int n;cin >> n;
  while(n--)
  {
    int x,y;
    cin >> x >> y;
    p.pb(R2vec(x,y));
  }
  ConvexHull CH(p);
  return 0;
}
