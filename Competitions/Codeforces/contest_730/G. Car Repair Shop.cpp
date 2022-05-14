/*
2016-11-03 19:50:00
https://codeforces.com/contest/730/problem/G
*/
# include <bits/stdc++.h>
 using namespace std;
 
 typedef long long ll;
 map<ll, ll> S;
 map<ll, ll>::iterator it;
 map<ll, ll>::iterator it2;
 int n;
 ll x, y, mi, mf, pi, pf, sum;
 bool flag;
 
 int main(){
 
    scanf("%d", &n);
    S[1] = 0;
    S[10005000000] = 1;
 
    for(int i = 1; i <= n; i++){
        scanf("%lld %lld", &x, &y);
        y = x + y - 1ll;
 
        it = S.begin();
        sum = 0;
        flag = false;
        while(it != S.end()){
 
            sum += it -> second;
 
            assert(sum <= 1);
 
            if(it -> second == 1){
                it2 = it;
                it2--;
                mi = (it2) -> first;
                mf = (it) -> first - 1;
 
                if(mi <= mf){
 
                if(mi <= x && y <= mf){
                    pi = x;
                    pf = y;
                    flag = true;
                    break;
                }
 
                if(mf-mi >= y-x && !flag){
                    flag = true;
                    pi = mi;
                    pf = mi + (y-x);
                }
                }
            }
            it++;
        }
 
        S[pi] += 1;
        S[pf+1] += -1;
        printf("%lld %lld\n", pi, pf);
    }
    //it = S.end();
    //it--;
    //printf("%lld %lld\n", it->first, it->second);
 
 return 0;
 }