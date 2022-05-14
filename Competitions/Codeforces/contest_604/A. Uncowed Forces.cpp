/*
2015-12-01 18:45:26
https://codeforces.com/contest/604/problem/A
*/

#include <bits/stdc++.h>
 
using namespace std;
 
double m1,m2,m3,m4,m5,w1,w2,w3,w4,w5,hs,hu,p1,p2,p3,p4,p5;
int main(){
 
    cin >> m1 >> m2 >> m3 >> m4 >> m5;
    cin >> w1 >> w2 >> w3 >> w4 >> w5;
    cin >> hs >> hu;
 
    p1 = max((double)0.3*(double)500,(double)((double)1-m1/(double)250)*(double)500-(double)50*w1);
    p2 = max((double)0.3*(double)1000,(double)((double)1-m2/(double)250)*(double)1000-(double)50*w2);
    p3 = max((double)0.3*(double)1500,(double)((double)1-m3/(double)250)*(double)1500-(double)50*w3);
    p4 = max((double)0.3*(double)2000,(double)((double)1-m4/(double)250)*(double)2000-(double)50*w4);
    p5 = max((double)0.3*(double)2500,(double)((double)1-m5/(double)250)*(double)2500-(double)50*w5);
 
    cout <<p1+p2+p3+p4+p5+100*hs-50*hu<<endl;
 
    return 0;
}