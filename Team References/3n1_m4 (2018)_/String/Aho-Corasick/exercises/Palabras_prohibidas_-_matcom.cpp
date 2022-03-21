//~ Aho-Corasick
// el menor texto en orden lexicografico que tiene L
// letras y no contiene ninguna palabra como substring
#include <bits/stdc++.h>
using namespace std;

const int MAX= 600*10*13+15, S = 26;

namespace aho_corasick{
  int num;
  int bad[MAX];
  int fa[MAX];
  int fail[MAX];
  int next[MAX][S];
  string ans;
  void clean(){
    num = 1;
    for(int i = 0; i < S; i++)next[num - 1][i] = 0;
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
    bad[curr] = 1;
  }
  
  void construct(){
    queue<int> Q;
    for (int i = 0;i < S;i++)
      if (next[0][i] ){
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
          while (u && !next[u][i] )  u = fail[u];
          fail[ v ] = next[u][i];
          bad[v] |= bad[next[u][i]];
        }
      }
    }
  }
  void printBad()
  {
    for(int i=0;i<num;++i)
      printf("%d %d\n", i, bad[i]);
  }
  void printFail()
  {
    for(int i=0;i<num;++i)
      printf("fail %d %d\n", i, fail[i]);
  }
  void solve(int s,int p, int k)
  {
    if(p == k)return;
    for(int i=0;i<S;++i)
    {
      int ns = s;
      while (next[ns][i] == 0)
          ns = fail[ns];
      ns = next[ns][i];
      if(!bad[ns] && ns)
      {
        ans+=(char)i+'a';
        solve(ns,p+1,k);
        break;
      }
    }
  }
};

char str[15];
int main()
{
  int n,k;
  scanf("%d%d", &n, &k);
  aho_corasick::aho_corasick();
  for(int i=1;i<=n;++i)
  {
    scanf("%s", str);
    aho_corasick::insert(str);
  }
 // aho_corasick::dfs();
  aho_corasick::construct();
  //~ aho_corasick::printBad();
  //~ aho_corasick::printFail();
  
  aho_corasick::solve(0,0,k);
  if((int)aho_corasick::ans.size() != k)return !(printf("Imposible\n"));
  printf("%s\n", aho_corasick::ans.c_str());
  
  return 0;
}
