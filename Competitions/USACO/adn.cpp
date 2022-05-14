/*
Ruddy Guerrero Alvarez
Villa Clara -- Caibarien
 OCI 2011
 2B
*/
 # include <algorithm>
 # include <cstdio>
 # include <cstring>
 using namespace std;

 typedef pair<int,int> par;
 par d[100005];
 int i, j, k, m, l, sol=1, lt, n, c;
 char s[1005], a[105];
 int ocu[105];

 int main(){

     freopen("adn.in", "r", stdin);
     freopen("adn.out", "w", stdout);

     scanf("%d\n%s\n", &n, s+1);

     lt = strlen(s+1);

     for(i = 1; i <= n; i++){

         scanf("%s ", a+1);
         l = strlen(a+1);

         // Pre KMP
         k = 0;
         for(j = 2; j <= l; j++){

             while(k > 0 && a[k+1] != a[j])
                k = ocu[k];

             if(a[k+1] == a[j])
                k++;

             ocu[j] = k;
         }
         // KMP
         k = 0;
         for(j = 1; j <= lt; j++){

            while(k > 0 && a[k+1] != s[j])
                k = ocu[k];

            if(a[k+1] == s[j])
                k++;
            if(k == l)
                d[c].first = j,
                d[c++].second = j - l + 1;
         }

     }

     sort(d, d+c);
     for(i = 1; i < c; i++){
        if(d[m].first < d[i].second)
            sol++,
            m = i;
     }

  printf("%d", sol);

  return 0;
 }
