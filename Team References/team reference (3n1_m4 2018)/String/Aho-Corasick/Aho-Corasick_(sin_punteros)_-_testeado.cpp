struct aho_corasick{
  int num;
  int pos[MAX];
  int fail[MAX];
  int link[MAX];
  int next[MAX][26];
  aho_corasick(){
      clean();
  }
  void insert(char* patt, int idx){
    int curr = 0;
    for (int j=0; patt[j]; j++){
      int a = patt[j] - 'a';
      if (next[curr][a] == 0){
        next[curr][a] = num++;
        for(int i = 0; i < 26; i++)next[num - 1][i] = 0;
        pos[num - 1] = fail[num - 1] = 0;
        link[num - 1] = -1;
      }
      curr = next[curr][a];
    }
    pos[curr] = idx;
  }
  void construct(){
    queue<int> Q;
    for (int i = 0;i < 26;i++)
      if ( next[0][i] ){
        fail[next[0][i]] = 0;
        Q.push( next[0][i] );
      }else next[0][i] = 0;
    while ( !Q.empty() ){
      int t = Q.front(); Q.pop();
      for (int i = 0; i < 26; i++){
        int v = next[t][i];
        if ( v ) {
          Q.push( v );
          int u = fail[t];
          while (  u && !next[u][i] )  u = fail[u];
          fail[ v ] = next[u][i];
          if ( pos[next[u][i]] != -1 ) link[next[t][i]] = next[u][i];
          else link[next[t][i]] = link[next[u][i]];
        }
      }
    }
  }
  void clean(){
    num = 1;
    for(int i = 0; i < 26; i++)next[num - 1][i] = 0;
    pos[num - 1] = fail[num - 1] = 0;
    link[num - 1] = -1;
  }
};
