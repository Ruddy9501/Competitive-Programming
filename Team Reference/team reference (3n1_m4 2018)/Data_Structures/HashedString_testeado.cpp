// testeado en http://matcomgrader.com/problem/9532/contando-personas/
typedef unsigned long long ull;
#define BASE 29
const ull Mod=1e9+7;
ull powe[2050];
void init()
{
  powe[0]=1;
  for(int i=1;i<=1010;i++)powe[i]=(powe[i-1]*BASE)%Mod;
}
int val(char x){return x-'a'+1;}
struct HashedString
{  
  string str;
  vector<ull> hash;
  HashedString(){}
  HashedString(string &str)
    :str(str), hash(str.size())
  {
    hash[0] = val(str[0]);
    for(int i=1;i<(int)hash.size();++i)
      hash[i] = (hash[i-1]*BASE%Mod + val(str[i]))%Mod;
  }
  ull hashCode(){return hash.back();}
  ull get_hash(int i,int j)
  {
    if(i > 0) return (hash[j]+Mod - hash[i-1]*powe[j-i+1]%Mod)%Mod;
    return hash[j];
  }
};
