#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, t;
char S[1000000];

int main(){

    freopen ("evenodd.in", "r", stdin);
    freopen ("evenodd.out", "w", stdout);

    scanf ("%d", &n);

    while(n--){
          scanf ("%s\n", S);
          t = strlen (S);
          if ((S[t-1] - 48) % 2 == 0)
              printf ("even\n");
           else
              printf ("odd\n");
    }

    return 0;
}
