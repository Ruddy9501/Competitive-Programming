#include <bits/stdc++.h>

using namespace std;

double pi = acos(-1);

int main(){
    
    int cas;
    scanf ("%d", &cas);
    for (int i = 1; i <= cas; ++i){
        long long r, a, b; 
        scanf ("%lld %lld %lld", &r, &a, &b); 
        double area = 0.0;
        while (r){
             area += pi*r*r + pi*(r*a)*(r*a);
             r = (r*a)/b;
        }
        
        printf ("Case #%d: %lf\n", i, area);
    }
    
    return 0;
}
