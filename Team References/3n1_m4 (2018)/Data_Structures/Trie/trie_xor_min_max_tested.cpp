// testeado en http://codeforces.com/contest/948/problem/D

const int N = 3e5+7; // #of words
const int L = 32; // length of word
const int S = 2; // size of alphabet
int t[N*L][S], c[N*L], sz=0;

struct trie_xor_min_max
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
};


