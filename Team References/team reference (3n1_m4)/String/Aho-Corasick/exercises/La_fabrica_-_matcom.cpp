#include <bits/stdc++.h>

using namespace std;


const int MAX = 3e3 + 5;

int n, l[MAX];
bool m[MAX];
char a[MAX];

vector <string> v;
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
namespace AhoCorasick
{
  struct node
  {
    typedef struct node* pnode;
    vector<pnode> next;
    pnode fail;
    int output;
    pnode sigt;
    node() : next(S,nullptr), fail(nullptr),
      output(-1), sigt(nullptr){}
  };
  typedef struct node* pnode;
  pnode root;
  vector<string> K; // keywords
  
  void enter(string &a,int i)
  {
    l[i] = (int)a.size();
    pnode s = root;
    int j=0;
    while(j < sz(a) && s->next[a[j]-'a'] != nullptr)
      s=s->next[a[j++]-'a'];
    for(;j<sz(a);++j)
    {
      s->next[a[j]-'a'] = new node;
      s = s->next[a[j]-'a'];
    }
    s->output = i;
  }

  void build_failure()
  {
    queue<pnode> q;
    for(int a=0;a<S;++a)
    {
      if(root->next[a] != root)
      {
        root->next[a]->fail = root;
        q.push(root->next[a]);
      }
    }
    while(sz(q))
    {
      pnode r = q.front();q.pop();
      for(int a=0;a<S;++a)
        if(r->next[a] != nullptr)
        {
          pnode s = r->next[a];
          q.push(s);
          
          pnode state = r->fail;
          while(state->next[a]==nullptr)state = state->fail;
          s->fail = state->next[a];

          if(~s->fail->output) s->sigt = s->fail;
          else if(s->fail->sigt != nullptr) s->sigt = s->fail->sigt;
        }else r->next[a] = r->fail->next[a];
    }
  }

  void match(string &a)
  {
    pnode s = root;
    for(int i=0;i<sz(a);++i)
    {
      s = s->next[a[i]-'a'];
      if(~s->output && m[i-l[s->output]+1]
        && l[s->output] != sz(a)){m[i+1] = 1; continue;}
      pnode cur = s->sigt;
      while(cur!=nullptr)
      {
        if(~cur->output && m[i-l[cur->output]+1]
          && l[cur->output] != sz(a)){m[i+1] = 1; break;}
        cur = cur->sigt;
      }
    }
  }
  
  //~ AhoCorasick(){}
  void init(vector<string> &v)
  {
    K = v;
    root = new node;
    for(int i=0;i<sz(K);++i)
      enter(K[i], i);
    for(int a=0;a<S;++a)
      if(root->next[a] == nullptr) root->next[a]=root;
    build_failure();
  }
}

set <string> ss;

int main(){

    scanf ("%d", &n);int sol = n;
    for (int i = 1; i <= n; ++i){
         scanf ("%s", a);
         string s = (string) a;
         if (ss.find (s) != ss.end()){
             sol--;
             continue;
         }

         ss.insert (s);

         v.push_back (s);
    }

    AhoCorasick::init (v);
    sort (v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++){
         string s = v[i]; //printf ("%s\n", s.c_str());
         memset (m, 0, sizeof (m));
         m[0] = 1;
         AhoCorasick::match (s);
         if (m[(int)s.size()]) sol--;
        // for (int j = 0; j <= (int)s.size(); ++j)
        // printf ("%d", m[j]);printf ("\n");
    }

    printf ("%d\n", sol);

    return 0;
}
