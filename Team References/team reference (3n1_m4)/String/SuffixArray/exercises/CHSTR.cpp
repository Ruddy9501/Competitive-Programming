/* Suffix Array - CHSTR (codechef)
For each test case, output Q lines,
each line should contain one integer
- amount of ways to choose exactly
Ki equal strings from the list L.
  Example:
  >> Input:
  1
  5 4
  ababa
  2
  1
  3
  4
  >> Output:
  7
  15
  1
  0
>> Explanation
L = {"a", "b", "a", "b", "a", "ab", "ba",
  "ab", "ba", "aba", "bab", "aba", "abab",
  "baba", "ababa"}.
k1 = 2: There are seven ways to choose two
  equal strings ("a", "a"), ("a", "a"),
  ("a", "a"), ("b", "b"), ("ab", "ab"),
  ("ba", "ba"), ("aba", "aba").
k2 = 1: We can choose any string from L (15 ways).
k3 = 3: There is one way to choose three equal
  strings - ("a", "a", "a").
k4 = 4: There are no four equal strings in L .
*/
#include <bits/stdc++.h>
using namespace std;

typedef int I;
typedef long long int LL;
typedef double D;
typedef long double LD;
typedef pair<I,I> PII;
typedef pair<D,D> PDD;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> PLD;
typedef complex<D> CPX;

typedef vector<I> VI;
typedef vector<LL> VLL;
typedef vector<D> VD;
typedef vector<LD> VLD;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef set<I> SI;
typedef set<LL> SLL;
typedef set<D> SD;
typedef set<LD> SLD;
typedef set<PII> SPII;
typedef set<PLL> SPLL;

#define endl '\n'
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define fd find
#define ins insert
#define ers erase
#define ifor(i,st,ed) for(I i=(st);i<=(ed);++i)
#define dfor(i,st,ed) for(I i=(st);i>=(ed);--i)
#define efor(it,x) for(auto it:(x))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define cout(p) cout<<fixed<<setprecision(p)
#define sum(x,st,ed) ((x)[ed]-(st>0?(x)[st-1]:0))
#define all(x) (x).begin(),(x).end()
#define sz(x) ((I)(x).size())

const int N = 5e3+7;
const LL MOD = 1e9+7;

namespace sa
{
  char s[N];
  int n, _sa[N], _b[N],  top[N], _tmp[N];
  int LCP[N], *SA = _sa, *B = _b, *tmp = _tmp;
  void blcp()
  {
      for(int i = 0, k = 0; i < n; ++i)
      {
          if(B[i] == n - 1)continue;
          for(int j = SA[B[i] + 1]; i + k < n &&
          j + k < n && s[i+k] == s[j + k] && s[i+k]!='$'; k++);
          LCP[B[i]+1] = k;
          if(k) k--;
      }
  }
  void bsa()
  {
    //memset 0 -> _sa, _b, _tmp, top, LCP
      s[n] = '\0', n ++;
      int na = (n < 256 ? 256 : n);
      for(int i = 0; i < n ; i++)top[B[i] = s[i]]++;
      for(int i = 1; i < na; i++)top[i] += top[i - 1];
      for(int i = 0; i < n ; i++)SA[--top[B[i]]] = i;
      for(int ok = 1,j = 0;ok < n && j < n-1;ok <<= 1)
      {
          for(int i = 0; i < n; i++)
          {
              j = SA[i] - ok;
              if (j < 0)j += n;
              tmp[top[B[j]]++] = j;
          }
          SA[tmp[top[0] = 0]] = j = 0;
          for(int i = 1; i < n; i++)
          {
              if(B[tmp[i]] != B[tmp[i - 1]] ||
                  B[tmp[i]+ok] != B[tmp[i-1] + ok])
                  top[++j] = i;
              SA[tmp[i]] = j;
          }
          swap(B, SA), swap(SA, tmp);
      }
      blcp();
      n --, s[n] = '\0';
  }
  I t[N][20],Log2[N];
  void brmq()
  {
    ifor(i,1,n)t[i][0]=LCP[i];
    I x = -1;
    ifor(i,1,N)
    {
      if(!(i&(i-1)))++x;
      Log2[i]=x;
    }
    for(I k=1;(1<<k)<=n;++k)
      for(I i=1;i+(1<<(k-1))<=n;++i)
        t[i][k] = min(t[i][k-1],t[i+(1<<(k-1))][k-1]);
  }
  I qlcp(I i,I j)
  {
    if(i>=j)return INT_MAX;
    I d=Log2[j-i];++i;
    return min(t[i][d],t[j-(1<<d)+1][d]);
  }
  void check()
  {
    ifor(i,1,n)
    {
      ifor(j,0,Log2[n])
        cerr << t[i][j] << ' ';
      cerr << endl;
    }
  }
}

LL C[N][N], P[N];

int bs(int lo,int hi,int l,int k)
{
  if(hi-lo<=1)
  {
    int f = sa::qlcp(k,hi); 
    if(f>=l)return hi;
    return lo;
  }
  int m = (lo+hi)>>1;
  int f = sa::qlcp(k,m);
  if(f>=l)
    return bs(m,hi,l,k);
  return bs(lo,m-1,l,k);
}

void init()
{
  for(int i=1;i<=sa::n;++i)
    for(int j=sa::LCP[i]+1;j<=sa::n-sa::SA[i];++j)
    {
      int up = bs(i,sa::n,j,i);
      ++P[up-i+1];
    }
}

LL ans[N];

inline void clean()
{//memset 0 -> _sa, _b, _tmp, top, LCP
  memset(sa::_sa,0,sizeof sa::_sa);
  memset(sa::_b,0,sizeof sa::_b);
  memset(sa::_tmp,0,sizeof sa::_tmp);
  memset(sa::top,0,sizeof sa::top);
  memset(sa::LCP,0,sizeof sa::LCP);
  memset(P,0,sizeof P);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  
  for(int i=0;i<N;++i)
  {
    C[i][0]=C[i][i]=1;
    for(int j=1;j<i;++j)
      C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
  }
  int t;cin >> t;
  while(t--)
  {
    int q;
    cin >> sa::n >> q;
    
    for(int i=0;i<sa::n;++i)
      cin >> sa::s[i];
    
    sa::bsa(); // O(Nlg^2N)
    sa::brmq(); // O(NlgN)
    
    init(); // computes P[i] - O(N^2lgN)
    memset(ans,-1,sizeof ans);
    while(q--)
    {
      int k; cin >> k;
      if(k>sa::n)
      {
        cout << "0\n";
        continue;
      }
      if(~ans[k])
      {
        cout << ans[k] << endl;
        continue;
      }
      ans[k]=0;
      for(int i=k;i<=sa::n;++i)
        ans[k] = (ans[k]+P[i]*C[i][k]%MOD)%MOD;
      cout << ans[k] << endl;
    }
    
    if(t)clean();
  }
  
  return 0;
}
