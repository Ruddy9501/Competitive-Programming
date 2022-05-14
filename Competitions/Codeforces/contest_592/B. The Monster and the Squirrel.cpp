/*
2015-11-18 23:37:44
https://codeforces.com/contest/592/problem/B
*/
#include <iostream>
 
using namespace std;
long long n;
int main(){
 
    cin >> n;
    if (n==3){
        cout<<"1"<<endl;
        return 0;
    }
 
    if (n==4){
        cout << "4"<<endl;
        return 0;
    }
 
    cout << n-2ll+2ll*(n-3ll)+(n-4ll)*(n-3ll)<<endl;
 
    return 0;
}