/* Suffix Array - SSTORY (codechef)
 * Encuentra la subcadena comun mas larga
 * entre dos cadenas, en caso de empate
 * la que primero aparezca en la segunda
 * va primero cadena.
 * Example:
 * >> Input:
 * adsyufsfdsfdsf
 * fdyusgfdfyu
 * >> Output:
 * fd
 * 2
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

const int N = 5e5+7;

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
          j + k < n && s[i+k] == s[j + k] && s[i+k] != '$'; k++);
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
  void check_SA()
  {
    cerr << "===Suffix Array===\n";
    ifor(i,0,n)
    {
      cerr << i << ' ';
      ifor(j,SA[i],n)cerr << s[j];
      cerr << ' ' << LCP[i];
      cerr << endl;
    }
    cerr << "==================\n";
  }
}

int id[N];

void check_SA()
  {
    cerr << "===Suffix Array===\n";
    ifor(i,0,sa::n)
    {
      cerr << i << ' ';
      ifor(j,sa::SA[i],sa::n)cerr << sa::s[j];
      cerr << ' ' << sa::LCP[i] << ' ' << id[sa::SA[i]];
      cerr << endl;
    }
    cerr << "==================\n";
  }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  
  string tmp;
  cin >> tmp;
  efor(c,tmp)
  {
    id[sa::n] = 1;
    sa::s[sa::n++]=c;
  }
  sa::s[sa::n++]='$';
  cin >> tmp;
  efor(c,tmp)
  {
    id[sa::n] = 2;
    sa::s[sa::n++]=c;
  }
  sa::s[sa::n++]='$';
  
  sa::bsa();
  sa::brmq();
  //check_SA();
  
  vector<int> pos[2];
  ifor(i,3,sa::n)
    pos[id[sa::SA[i]]-1].pb(i);
  
  PII ans=mp(-1,-1);
  
  auto upd_ans=[&](int x,int len)
  {
    if(ans.fr < len)
    {
      ans.fr = len;
      ans.sc = sa::SA[x];
    }else if(ans.fr == len)
      if(ans.sc > sa::SA[x])
        ans.sc = sa::SA[x];
  };
  
  efor(it,pos[1])
  {
    auto up=ub(all(pos[0]),it);
    if(up == pos[0].begin())
    {
      int lcp=sa::qlcp(it,*up);
      upd_ans(it,lcp);
    }else if(up == pos[0].end())
    {
      up--;
      int lcp=sa::qlcp(*up,it);
      upd_ans(it,lcp);
    }else
    {
      int lcp=sa::qlcp(it,*up);
      upd_ans(it,lcp);
      up--;
      lcp=sa::qlcp(*up,it);
      upd_ans(it,lcp); 
    }
  }
  
  if(!ans.fr)
  {
    cout << "0\n";
    return 0;
  }
  for(int i=ans.sc,j=1;j<=ans.fr;++i,++j)
    cout << sa::s[i];
  cout << endl << ans.fr << endl;
  
  return 0;
}
