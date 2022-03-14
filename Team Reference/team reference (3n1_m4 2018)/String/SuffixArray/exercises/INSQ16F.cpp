/* Suffix Arrays
If LCP of Xth and Yth strings is L then how many
times L occures in the set as a substring of any string? 
  Example
  Input:
  4
  ababa
  aba
  abcd
  cbab
  3
  1 2
  2 3
  1 4
  Output:
  3
  5
  0
*/
#include <bits/stdc++.h>
using namespace std;

typedef int I;
typedef pair<I,I> PII;

#define endl '\n'
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define fd find
#define sz(v) ((I)(v).size())
#define ifor(i,st,ed) for(I i=(st);i<=(ed);++i)
#define dfor(i,st,ed) for(I i=(st);i>=(ed);--i)
#define efor(it,x) for(auto it:(x))
#define all(x) (x).begin(),(x).end()

const int N = 6e5+7;

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

int slen[N],pos[N],x[N];

int bs1(int lo,int hi,const int &fx,const int &lcp)
{
  if(hi-lo<=1)
  {
    int f1=sa::qlcp(lo,fx);
    if(f1>=lcp)return lo;
    return hi;
  }
  int m=(lo+hi)>>1;
  int f=sa::qlcp(m,fx);
  if(f>=lcp)
    return bs1(lo,m,fx,lcp);
  return bs1(m+1,hi,fx,lcp);
}
int bs2(int lo,int hi,const int &fx,const int &lcp)
{
  if(hi-lo<=1)
  {
    int f1=sa::qlcp(fx,hi);
    if(f1>=lcp)return hi;
    return lo;
  }
  int m=(lo+hi)>>1;
  int f=sa::qlcp(fx,m);
  if(f>=lcp)
    return bs2(m,hi,fx,lcp);
  return bs2(lo,m-1,fx,lcp);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  
  int n; cin >> n;sa::n=0;
  string tmp;
  ifor(i,1,n)
  {
    cin >> tmp;
    slen[i]=sz(tmp);
    pos[i]=sa::n;
    efor(c,tmp)
    {
      sa::s[sa::n++]=c;
    }
    sa::s[sa::n++]='$';
  }
  
  sa::bsa();sa::brmq();
  
  // * cerr << "===Suffix Array===\n";
  // * ifor(i,0,sa::n)
  // * {
    // * cerr << i << ' ';
    // * ifor(j,sa::SA[i],sa::n)cerr << sa::s[j];
    // * cerr << ' ' << sa::LCP[i];
    // * cerr << endl;
  // * }
  // * cerr << "==================\n";
  
  ifor(i,1,sa::n)
    x[sa::SA[i]] = i;
  ifor(i,1,n)
    pos[i]=x[pos[i]];
  
  int q;cin >> q;
  while(q--)
  {
    int u,v; cin >> u >> v;int tmp=slen[u];
    u = pos[u];v = pos[v];
    if(u>v)swap(u,v);
    int lcp=min(sa::qlcp(u,v),tmp);
    
    if(!lcp)
    {
      cout << "0\n";
      continue;
    }
    
    int lo = bs1(1,u,u,lcp);
    int hi = bs2(v,sa::n,v,lcp);
    
    //cerr << lo << ' ' << hi << endl;
    cout << hi-lo+1 << endl;
  }
  
  return 0;
}
