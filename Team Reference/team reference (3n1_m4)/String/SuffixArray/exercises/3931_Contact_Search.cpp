// coj - 3931
/*
* For each name, in the same order given in the input,
* print a line containing the shortest pattern that is
* able to distinguish that contact name from the other
* names. If there are multiple patterns, print the
* lexicographically smallest. If there is no pattern,
* print the word 'IMPOSSIBLE'
*/
#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef pair<int,int> PII;

#define endl '\n'
#define fr first
#define sc second
#define mp make_pair
#define ifor(i,st,ed) for(I i=(st);i<=(ed);++i)
#define dfor(i,st,ed) for(I i=(st);i>=(ed);--i)

const I MAX = 1e6+7;
const I LEN = 1e6+7;
char s[LEN];
int n, _sa[LEN], _b[LEN],  top[LEN], _tmp[LEN];
int LCP[LEN], *SA = _sa, *B = _b, *tmp = _tmp;
void build_lcp (){
    for(int i = 0, k = 0; i < n; ++i){
        if(B[i] == n - 1)
            continue;
        for(int j = SA[B[i] + 1]; i + k < n &&
				j + k < n && s[i+k] == s[j + k]; k++);
        LCP[B[i]] = k;
        if( k ) k--;
    }
}
void build_sa (){
	//memset 0 -> _sa, _b, _tmp, top, LCP
    s[n] = '\0', n ++;
    int na = (n < 256 ? 256 : n);
    for (int i = 0; i < n ; i++)
        top[B[i] = s[i]]++;
    for (int i = 1; i < na; i++)
        top[i] += top[i - 1];
    for (int i = 0; i < n ; i++)
        SA[--top[B[i]]] = i;
    for (int ok = 1,j = 0;ok < n && j < n-1;ok <<= 1){
        for (int i = 0; i < n; i++){
            j = SA[i] - ok;
            if (j < 0)
                j += n;
            tmp[top[B[j]]++] = j;
        }
        SA[tmp[top[0] = 0]] = j = 0;
        for (int i = 1; i < n; i++){
            if (B[tmp[i]] != B[tmp[i - 1]] ||
				B[tmp[i]+ok] != B[tmp[i-1] + ok])
                top[++j] = i;
            SA[tmp[i]] = j;
        }
        swap(B, SA), swap(SA, tmp);
    }
    build_lcp();
    n --, s[n] = '\0';
}

char tmp0[MAX];
I id[MAX],x0[MAX],l[MAX],lamda[MAX];
PII ans[MAX]; // <length, pos>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  I tot; cin >> tot;
  ifor(i,1,tot)
  {
    cin >> tmp0;
    I len = strlen(tmp0);
    l[i]=len;
    x0[i] = n;
    ifor(j,0,len-1)
    {
      id[n] = i;
      s[n++] = tmp0[j];
    }
    s[n++]='$';
  }

  build_sa();
  fill(ans,ans+n+1,mp(INT_MAX,INT_MAX));

  // algorithm goes here
  I st=0;
  I *high=LCP;
  ifor(i,0,n-1)SA[i]=SA[i+1];
    
  while(st<n)
  {
    I mn=INT_MAX;
    while(st<n-1)
    {
      mn = min(mn,high[st]);
      lamda[st] = mn;
      if(id[SA[st]]!=id[SA[st+1]])
      {
        ++st;
        break;
      }
      ++st;
    }
    if(st==n-1)
    {
      if(id[SA[st-1]]!=id[SA[st]])
        lamda[st]=high[st];
      else lamda[st] = min(mn,high[st]);
      ++st;
    }
  }
  //cerr << "Part 1 Complete\n";
  st=n-1;high[n]=0;
  while(~st)
  {
    I mn=INT_MAX;
    while(st)
    {
      mn=min(mn,high[st+1]);
      lamda[st]=max(lamda[st],mn);
      if(id[SA[st]]!=id[SA[st-1]])
      {
        --st;
        break;
      }
      --st;
    }
    if(!st)
    {
      if(id[SA[st]]!=id[SA[st+1]])
        lamda[st] = high[st+1];
      else lamda[st]=max(lamda[st],min(mn,high[st+1]));
      --st;
    }
  }
  
  //cerr << "Part 2 Complete\n";
  ifor(i,0,n-1)
  {
    if(s[SA[i]]=='$')continue;
    I xid=id[SA[i]];
    I sln=x0[xid]+l[xid]-SA[i];
    I tmp=lamda[i];
    if(tmp>=sln)continue;
    if(ans[xid].fr>tmp+1)
    {
      ans[xid].fr=tmp+1;
      ans[xid].sc=SA[i];
    }
  }

  ifor(i,1,tot)
  {
    if(ans[i].fr==INT_MAX)
    {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    for(int j=0, x=ans[i].sc;j<ans[i].fr;++j,++x)
      cout << s[x];
    cout << endl;
  }
  //cerr << "Part 3 Complete\n";
  return 0;
}
