/*
2015-12-09 19:27:55
https://codeforces.com/contest/606/problem/A
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int P[] = {1,2,3}, sum, res;
 
struct par{
       int x, y;
}A[10];
 
int main(){
 
    cin >> A[1].x >> A[2].x >> A[3].x;
    cin >> A[1].y >> A[2].y >> A[3].y;
 
    for (int i = 1; i <= 3; i++){
         if (A[i].x >= A[i].y) sum += (A[i].x-A[i].y)/2;
          else res += A[i].y-A[i].x;
    }
 
    if (sum < res) cout << "No"<<endl;
     else cout << "Yes"<<endl;
 
    return 0;
}