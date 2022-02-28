//Bronce 2010-2011 March
 # include <cmath>
 # include <cstdio>
 using namespace std;

 int l, c, n, i, x, y;

 int ab(int x){
    if(x < 0)
        return -x;
    return x;
 }

 int main(){

    freopen("charms.in", "r", stdin);
    freopen("charms.out", "w", stdout);

    scanf("%d %d %d", &l, &c, &n);
    for(i = 1; i <= c; i++){
        scanf("%d %d", &x, &y);
        printf("%d\n", x+ab(y-n));
    }
  return 0;
 }
