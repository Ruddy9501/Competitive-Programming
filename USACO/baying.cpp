/*
Ruddy Guerrero Alvbarez
Villa Clara -> Caibarien
USACO\ORO\marzo\2008-2009
Mugiendo a la Luna\baying
*/
#include <queue>
#include <cstdio>

#define RAN 4000005
using namespace std;

int n, m, a1, b1, c1, a2, b2, c2, con, p1, p2;
long long s1, s2, S[RAN];

priority_queue <long long, vector<long long>, greater <long long> >Q1, Q2;

int main(){

    freopen ("baying.in", "r", stdin);
    freopen ("baying.out", "w", stdout);

    scanf ("%d %d", &n, &m);
    scanf ("%d %d %d", &a1, &b1, &c1);
    scanf ("%d %d %d", &a2, &b2, &c2);

    p1 = p2 = con = 1;
    S[1] = n;

    while (con < m){
           s1 = a1*S[p1]/c1+b1;
           s2 = a2*S[p2]/c2+b2;
           if (s1 < s2){
               p1++;
               if (S[con] != s1){
                   S[++con] = s1;
               }
           }
           else{
               p2++;
               if (S[con] != s2){
                   S[++con] = s2;
               }
           }
    }

    printf ("%lld\n", S[con]);

    return 0;
}
