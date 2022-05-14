/*
2016-04-27 18:27:40
https://codeforces.com/contest/161/problem/B
*/
# include <bits/stdc++.h>
 using namespace std;
 
 struct par {
    int val, id;
 
    bool operator < (const par &a)const{
        return val > a.val;
    }
 };
 
 vector<par> v[1005];
 par A[1005], B[1005];
 int c1, c2, ck, n, k, x, y;
 double sol = 0;
 
 int main(){
 
 
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &x, &y);
 
        if(y == 1)A[++c1] = (par){x, i};
        if(y == 2)B[++c2] = (par){x, i};
        sol += x;
    }
 
    sort(A+1, A+c1+1);
    sort(B+1, B+c2+1);
/*
    for(int i = 1; i <= c1; i++)
        printf("%d %d\n", A[i].val, A[i].id);*/
 
    for(ck = 1; ck < k && ck <= c1; ck++)
        sol -= A[ck].val/2.0;
 
    if(c1 >= k){
        if(c2 > 0)
            sol -= min(A[c1].val, B[c2].val)/2.0;
        else
            sol -= A[c1].val/2.0;
    }
 
    printf("%0.1lf\n", sol);
 
    for(ck = 1; ck < k && ck <= c1; ck++)
        printf("1 %d\n", A[ck].id);
 
    if(c1 >= k){
        printf("%d", n-ck+1);
        for(int i = 1; i <= c2; i++)
            printf(" %d", B[i].id);
        for(; ck <= c1; ck++)
            printf(" %d", A[ck].id);
        printf("\n");
    }
    else {
        for(; ck < k; ck++)
            if(ck <= c1)printf("1 %d\n", A[ck].id);
            else printf("1 %d\n", B[c2--].id);
 
        printf("%d", c2);
        while(c2){
            printf(" %d", B[c2].id);
            c2--;
        }
        printf("\n");
    }
 
 
 
 return 0;
 }