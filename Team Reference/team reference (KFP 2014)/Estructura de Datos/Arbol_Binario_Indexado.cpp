# include <cstdio>
 using namespace std;

 int tm, op, p;
 typedef long long ll;

 struct date{
    int save[10005];

    void update(int p, ll v){
        for(int i = p; i <= tm; i += i& -i)
            save[i] += v;
    }

    ll query(int p){
        int sum=0;
        for(int i = p; i > 0; i -= (i & -i))
            sum += save[i];
        return sum;
    }

 }bit;

 int main(){

    scanf("%d", &tm);
    while(1){

        scanf("%d %d", &op, &p);

        if(op == -1)
            return 0;

        if(op)
            bit.update(p);
        else
            bit.print(p);
    }

 }
