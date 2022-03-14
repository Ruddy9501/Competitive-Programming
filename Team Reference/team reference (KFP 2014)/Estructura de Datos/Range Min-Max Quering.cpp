# include <cstdio>
 # include <cmath>
 # include <algorithm>
 using namespace std;

 int mat[5005][20];
 int n, p2, p1, q;

 void Build_RMQ(){

    int cc = (int) log2(n);
    int p = n, a, i, j;
    for(i = 1; i <= cc; i++){
        a = 1 << (i-1);
        p -= a;
        for(j = 1; j <= p; j++)
            mat[j][i] = min(mat[j][i-1], mat[j+a][i-1]);
    }
 }

 void find_RMQ(){
        int c = (int)log2(p2-p1);
        printf("%d\n", min(mat[p1][c], mat[p2-(1<<c)+1][c]));
 }

 int main(){


    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &mat[i][0]);


    Build_RMQ();

    while(q--){
        scanf("%d %d", &p1, &p2);
        find_RMQ();
    }

  return 0;
 }
