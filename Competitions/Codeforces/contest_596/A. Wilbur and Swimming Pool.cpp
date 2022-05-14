/*
2015-11-16 23:05:14
https://codeforces.com/contest/596/problem/A
*/
#include <iostream>
#include <algorithm>
 
using namespace std;
int x1,x2,y1,y2,n,X[10],Y[10];
int main(){
 
    cin >> n;
    for (int i = 1; i <= n; i++){
         cin >> X[i] >> Y[i];
         if (i==1){
                x1 = X[i];
                y1 = Y[i];
            continue;
         }
         if (X[i]!=x1)x2=X[i];
         if (Y[i]!=y1)y2=Y[i];
    }
 
    if (n==1 ||(n==2&&(X[1]==X[2]||Y[1]==Y[2]))){
        cout <<"-1"<<endl;
    }
    else
    cout << abs(x1-x2)*abs(y1-y2) <<endl;
 
 
    return 0;
}