//~ Aho-Corasick
// el menor texto en orden lexicografico que
// tiene L letras y con cantidad total de
// ocurrencias igual a K
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INIT ios_base::sync_with_stdio(false);\
             cin.tie(0),cout.tie()
#define endl '\n'
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ers erase
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define unique(x) (x).resize(unique(all(x))-(x).begin())
#define debug(_fmt,...) \
fprintf(stderr,"("#__VA_ARGS__ ") = (" _fmt")\n",__VA_ARGS__)

const int S = 26;
const int MAX = 107*20;

namespace aho_corasick{
  int num;
  int mk[MAX];
  int fail[MAX];
  int next[MAX][S];
  char memo[MAX][MAX][17];
  void clean(){
    num = 1;
    for(int i = 0; i < S; i++)next[num - 1][i] = 0;
    memset(memo, -1, sizeof memo);
  }
  void aho_corasick(){
      clean();
  }
  void insert(char* patt){
    int curr = 0;
    for (int j=0; patt[j]; j++){
      int a = patt[j] - 'a';
      if (next[curr][a] == 0){
        for(int i=0;i<S;++i)
        {
          next[curr][i] = num++;
        }
      }
      curr = next[curr][a];
    }
    mk[curr] = 1;
  }
  void construct(){
    queue<int> Q;
    for (int i = 0;i < S;i++)
      if ( next[0][i] ){
        fail[next[0][i]] = 0;
        Q.push( next[0][i] );
      }else next[0][i] = 0;
    while ( !Q.empty() ){
      int t = Q.front(); Q.pop();
      for (int i = 0; i < S; i++){
        int v = next[t][i];
        if ( v ) {
          Q.push( v );
          int u = fail[t];
          while (  u && !next[u][i] )  u = fail[u];
          fail[ v ] = next[u][i];
          mk[v] += mk[fail[v]];
        }
      }
    }
  }


  string ans;
  char can(int s,int l, int k)
  {
    //~ printf("%d %d %d\n", s, l, k);
    if(~memo[s][l][k]) return memo[s][l][k];

    char &res = memo[s][l][k];
    res=0;
    if((l <= 0 && k) || k < 0)
      return res = 0;
    if(!l && !k)
      return res = 1;

    for(int i=0;i<S;++i)
    {
      int ns = s;
      while (next[ns][i] == 0)
          ns = fail[ns];
      ns = next[ns][i];
      ans += (char) i + 'a';
      int tem = can(ns,l-1,k-mk[ns]);
      if(tem){
        res = 1;
        break;
      }
      ans.pop_back();
    }
    return res;
  }
}

char str[11];

int main()
{
  #ifdef OJUDGE
    //~ freopen("in","r",stdin);
  #endif

  aho_corasick::clean();

  int n,l,k;
  scanf("%d%d%d", &n, &l, &k);
  for(int i=1;i<=n;++i)
  {
    scanf("%s", str);
    aho_corasick::insert(str);
  }

  aho_corasick::construct();

  if(!aho_corasick::can(0,l,k)) return !(cout <<"Imposible\n");
  cout << aho_corasick::ans << endl;

  return 0;
}
//~ c
