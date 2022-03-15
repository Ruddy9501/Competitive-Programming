//~ 470D - codeforces
/*  Minimize Xor
 * For given A and P, find the lexicographically
 * smallest message O, for which there exists a
 * permutation pi such that (Oi xor pi(Pi) = Ai) for every i.
 */
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC \
target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INIT ios_base::sync_with_stdio(false);\
             cin.tie(0),cout.tie();
#define endl '\n'
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ins insert
#define ers erase
#define all(x) (x).begin(),(x).end()
#define unique(x) (x).resize(unique(all(x))-(x).begin())

const int N = 3e5+7; // #of words
const int L = 32; // length of word
const int S = 2; // size of alphabet
int t[N*L][S], c[N*L], sz=0;

struct xorm
{
  #define MIN_XOR // comment for max
  void add(int v)
  {
    int u=0;
    for(int i=30;~i;--i)
    {
      ++c[u];
      int b = (v>>i) & 1;
      if(!t[u][b])
        t[u][b] = ++sz;
      u=t[u][b];
    }
    ++c[u];
  }
  void rem(int v)
  {
    int u=0;
    for(int i=30;~i;--i)
    {
      --c[u];
      int b = (v>>i) & 1;
      u=t[u][b];
    }
    --c[u];
  }
  pii qry(int v)
  {
    int u=0,xorn=0,val=0;
    for(int i=30;~i;--i)
    {
      int b = (v>>i) & 1;
      #ifdef MIN_XOR
      if(t[u][b] && c[t[u][b]])
      {
        //~ cout<<" same "<<i<<' '<<b<<endl;
        val|=b*(1<<i);
        u=t[u][b];
      }else
      {
        //~ cout<<" diff "<<i<<' '<<(b^1)<<endl;
        val|=(b^1)*(1<<i);
        xorn|=(1<<i);
        u=t[u][b^1];
      }
      #endif
      #ifndef MIN_XOR
      if(t[u][b^1] && c[t[u][b^1]])
      {
        val|=(b^1)*(1<<i);
        xorn|=(1<<i);
        u=t[u][b^1];
      }else
      {
        val|=b*(1<<i);
        u=t[u][b];
      }
      #endif
    }
    return mp(xorn,val);
  }
}X;

int n;
int a[N],p[N];

int main()
{
  INIT
  cin>>n;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
  }

  for(int i=1;i<=n;++i)
  {
    int p;cin>>p;
    X.add(p);
  }
  
  //~ while(true)
  //~ {
    //~ int p;cin>>p;
    //~ if(p==-1)break;
    //~ cout<<X.qry(p).fr<<endl;
  //~ }
  
  for(int i=1;i<=n;++i)
  {
    pii best=X.qry(a[i]);
    cout<<best.fr<<' ';
    X.rem(best.sc);
  }
  
  return 0;
}
