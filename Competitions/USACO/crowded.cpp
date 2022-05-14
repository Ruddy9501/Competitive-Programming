/*
Usaco/2013-2014/plata/noviembre
*/
 # include <set>
 # include <cstdio>
 # include <algorithm>
 using namespace std;

 struct par {
    int x, h;
    bool operator < (const par &a)const{
        return x < a.x;
    }
 }A[50005];

 struct tri {
    int h, id;
 };

 struct cmp_x{
    bool operator () (const tri &a, const tri &b)const{
        return a.h > b.h;
    }
 };

 multiset <tri, cmp_x> S;
 multiset <tri, cmp_x>::iterator lo;

 int n, d, i, x, y, l, sol;
 bool mk[50005];

 int main(){

    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);

    scanf("%d %d", &n, &d);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &x, &y);
        A[i] = (par){ x, y};
    }

    sort(A+1, A+n+1);
    l = 1;
    for(i = 1; i <= n; i++){
        while(A[i].x-A[l].x > d){
            lo = S.begin();
            if(mk[l] == true && lo -> h >= A[l].h*2)
                sol++;
            S.erase(S.find((tri){A[l].h, l++}));
        }

        lo = S.begin();
        if(lo -> h >= 2*A[i].h)
            mk[i] = true;

        S.insert((tri){A[i].h, i});
    }

    for(i = l; i < n; i++){
        lo = S.begin();
        if(mk[i] == true && lo -> h >= A[i].h*2)
            sol++;
        S.erase(S.find((tri){A[i].h, i}));
    }


    printf("%d", sol);
    return 0;
 }
