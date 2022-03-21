#include <bits/stdc++.h>
using namespace std;
#define ifor(i,st,ed) for(int i=(st);i<=(ed);++i)
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
  int t[N][20],Log2[N];
  void brmq()
  {
    ifor(i,1,n)t[i][0]=LCP[i];
    int x = -1;
    ifor(i,1,N)
    {
      if(!(i&(i-1)))++x;
      Log2[i]=x;
    }
    for(int k=1;(1<<k)<=n;++k)
      for(int i=1;i+(1<<(k-1))<=n;++i)
        t[i][k] = min(t[i][k-1],t[i+(1<<(k-1))][k-1]);
  }
  int qlcp(int i,int j)
  {
    if(i>=j)return INT_MAX;
    int d=Log2[j-i];++i;
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
      cerr << ' ' << LCP[i] << endl;
    }
    cerr << "==================\n";
  }
}
int main()
{
  return 0;
}
