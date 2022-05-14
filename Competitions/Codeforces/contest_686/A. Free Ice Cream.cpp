/*
2016-06-24 16:46:58
https://codeforces.com/contest/686/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
 
long long n, T,can;
 
int main (){
 
    cin >> n >> T;
    for (int i = 1;i <= n; i++){
         char car; long long t;
         cin >> car >> t;
         if (car == '-'){
             if (T >= t) T-=t;
              else can++;
         }
         else
            T += t;
    }
 
    cout << T << " " << can <<endl;
 
	return 0;
}