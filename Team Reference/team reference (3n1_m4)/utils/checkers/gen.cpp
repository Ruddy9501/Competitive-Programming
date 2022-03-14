#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(nullptr));
  int tc;
  cin >> tc;
  while(tc--)
  {
    string str;
    stringstream ss;
    ss << tc;
    ss >> str;
    str = "intro"+str;
    freopen(str.data(),"w",stdout);
    // Code goes here ... 
    fflush(stdout);
  }

  return 0;
}
