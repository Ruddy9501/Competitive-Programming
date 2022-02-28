/*
2015-04-20 20:47:20
https://codeforces.com/contest/535/problem/A
*/
#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
int n;
map <int,string> m;
 
int main(){
 
    m [0] = "zero";
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";
    m[10] = "ten";
    m[11] = "eleven";
    m[12] = "twelve";
    m[13] = "thirteen";
    m[14] = "fourteen";
    m[15] = "fifteen";
    m[16] = "sixteen";
    m[17] = "seventeen";
    m[18] = "eighteen";
    m[19] = "nineteen";
    m[20] = "twenty";
    m[30] = "thirty";
    m[40] = "forty";
    m[50] = "fifty";
    m[60] = "sixty";
    m[70] = "seventy";
    m[80] = "eighty";
    m[90] = "ninety";
 
    cin >> n;
 
    if (n >= 0 && n <= 20) cout << m[n] <<endl;
     else if (n%10==0) cout << m[n] <<endl;
      else cout << m[(n/10)*10] <<"-" <<m[n%10]<<endl;
 
    return 0;
}