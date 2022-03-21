// testeado en CODF476E
struct trie {
  bool mk;
  trie* next[0x100];
  trie() { fill(next, next+0x100, nullptr);mk=false;}
};

trie* wadd(string& s, trie* r)
{
  for(char c: s)
  {
    if(r->next[c] == nullptr)
      r->next[c] = new trie;
    r = r->next[c];
  }
  r->mk=true;
  return r;
}

trie* root=new trie;
