/*
2015-04-26 22:07:33
https://codeforces.com/contest/538/problem/A
*/
#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
 
using namespace std;
 
int main(){
    string s;
    cin>>s;
    for(int i = 0; i<s.length(); i++)
        for(int j = i+1; j<=s.length(); j++)
            if(s.substr(0,i)+s.substr(j)=="CODEFORCES"){
                puts("YES");
                return 0;
            }
 
    puts("NO");
    return 0;
}