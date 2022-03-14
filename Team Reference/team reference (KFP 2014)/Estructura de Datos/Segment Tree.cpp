# include <iostream>
 # include <algorithm>
 # define oo 1 << 29
 # define RANG 30000000
 using namespace std;

 char c;
 int r1, r2, r3, i, Q;

 struct S_Tree{
    int n;
    int elements[5005];
    int T[RANG], Mk[RANG];

    int Build(int x, int xend, int P = 1){

        if(x == xend)
            return T[P] = elements[x];

        int pv = (x+xend)/2;
        return T[P] = Build(x, pv, P*2) + Build(pv+1, xend, P*2+1);
    }

    void Lazy_propagation(int x, int xend, int P){
        if(x == xend)
            return;

        int pv = (x+xend)/2;

        T[P*2] += (pv - x + 1)* Mk[P];
        T[P*2+1] += (xend - pv )* Mk[P];

        Mk[P*2] += Mk[P];
        Mk[P*2+1] += Mk[P];

        Mk[P] = 0;
    }

    int Query(int x, int xend, int P = 1){

        if(r2 < x || xend < r1)
            return 0;

        if(Mk[P])
            Lazy_propagation(x, xend, P);

        if(r1 <= x && xend <= r2)
            return T[P];

        int pv = (x+xend)/2;
        return Query(x, pv, P*2) + Query(pv+1, xend, P*2+1);
    }

    int Update(int x, int xend, int P = 1){

        if(Mk[P])
            Lazy_propagation(x, xend, P);

        if(r2 < x || xend < r1)
            return T[P];

        if(r1 <= x && xend <= r2){
            Mk[P] += r3;
            T[P] += ((xend-x)+1)*r3;
            return T[P];
        }

        int pv = (x+xend)/2;
        return T[P] = Update(x, pv, P*2) + Update(pv+1, xend, P*2+1);
    }
 }St;

 int main(){
    cin >> St.n;
    for(i = 1; i <= St.n; i++)
        cin >> St.elements[i];
   St.Build(1, St.n);
    cin >> Q;
    while(Q--){
        cin >> c >> r1 >> r2;
        if(c == 'Q')
            cout << St.Query(1, St.n) << endl;
        else{
            cin >> r3;
            St.Update(1, St.n);
        }
    }

 return 0; }
