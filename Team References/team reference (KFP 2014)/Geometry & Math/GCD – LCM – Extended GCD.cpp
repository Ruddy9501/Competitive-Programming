# include <cstdio>
 # include <iostream>
 # include <algorithm>
 using namespace std;

 int GCD(int a, int b){
    while(a){
        b %= a;
        swap(a, b);
    }
    return b;
 }

 int GCD_extended(int a, int b, int &x, int &y){
    if(a == 0 ){
        x = 0; y = 1;
        return b;
    }

    int x1, y1;
    int d = GCD_extended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
 }

 int a, b, g, x, y;

 int main(){

    cin >> a >> b;

    g = GCD_extended(a, b, x, y);
    cout << x << " " << y << " "<< g << " " << endl;
}
