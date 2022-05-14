/*
Ruddy Guerrero Alvarez
Villa Clara -- Caibarien 
USCAO 2008-2009
Marzo Plata
*/
 # include <cstdio>
 using namespace std;

 int n, i, x;
 int s[100005], a[100005];

 int main(){

    freopen("lookup.in", "r", stdin);
    freopen("lookup.out", "w", stdout);

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    a[0] = 1 << 29;
    for(i = n-1; i > 0; i--){
         x = i + 1;

         while(a[i] >= a[x] )
            x = s[x];

         s[i] = x;
        }

     for(i = 1; i <= n; i++)
        printf("%d\n", s[i]);
  return 0;
 }
    