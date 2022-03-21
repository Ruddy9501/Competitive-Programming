// testeado coj - 2440, 2250,
// https://codeforces.com/contest/1017/problem/E
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

template<class C>
struct KMP
{
  C p;
  vector<int> fail; // fail[j] = mayor i tq S[0..i] == S[j-i..j]
                    // o -1 si no existe tal prefijo
  KMP(C &p):p(p),fail(sz(p))
  {
    for(int i=0,j=-2;i<sz(p);fail[i] = ++j, ++i)
      while(j>-2&&p[j+1]!=p[i])if(j==-1)j=-2;else j=fail[j];
  }
  vector<int> all_match(C &text, bool overlap=true)
  {
    vector<int> res;
    for(int i=0,j=-1;i<sz(text);++i)
    {
      while(j>-2&&p[j+1]!=text[i])if(j==-1)j=-2;else j=fail[j];
      if(++j==sz(p)-1)res.pb(i-j),j=overlap?fail[j]:-1;
    }
    return res;
  }
  bool match(C &text)
  {
    //~ return sz(all_match(text)) > 0;
    for(int i=0,j=-1;i<sz(text);++i)
    {
      while(j>-2&&p[j+1]!=text[i])if(j==-1)j=-2;else j=fail[j];
      if(++j==sz(p)-1)return true;
    }
    return false;
  }
};

int main()
{
  vector<int> p;
  int n,ol;cin >> n;
  while(n--){int x;cin >> x;p.pb(x);}
  KMP<vector<int>> kmp(p);

  while(1)
  {
    cin >> n >> ol;
    p.clear();
    while(n--){int x;cin >> x;p.pb(x);}
    auto ans = kmp.all_match(p,ol);
    for(int i: ans) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
