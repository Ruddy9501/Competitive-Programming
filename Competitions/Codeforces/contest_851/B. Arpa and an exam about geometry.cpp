/*
2017-09-05 17:06:53
https://codeforces.com/contest/851/problem/B
*/
 # include <cstdio>
 # include <algorithm>
 using namespace std;
 
const double Pi = acos(-1);
const double EPS = 1e-8;
 struct Point{double x, y;} Array[1005], p;
 struct Rect{double A, B, C;} R1, R2;
 double d, d1;
 int a, b, c, i, n, Q;
 bool mk;
 
 Rect Find(int i, int j){
    Rect S;
    Point p;
 
    S.A = Array[j].x-Array[i].x;
    S.B = Array[j].y-Array[i].y;
 
    int g = __gcd(int(Array[j].x-Array[i].x), int(Array[j].y-Array[i].y));
 
    S.A/=g; S.B/=g;
 
    p.x = (Array[i].x+Array[j].x)/2;
    p.y = (Array[i].y+Array[j].y)/2;
 
    //printf("Point %.2lf %.2lf\n", p.x, p.y);
 
    S.C = -(S.A*p.x + S.B*p.y);
    return S;
 }
 
 Point Intersection(Rect I, Rect J){
    Point S;
    //if(I.B == 0)
 
    if(I.A == 0)swap(I, J);
    S.y = (-J.C*I.A + I.C*J.A)/(I.A*J.B - J.A*I.B);
    S.x = (-I.B*S.y-I.C)/I.A;
 
    return S;
 }
 
 
 int main(){
 
     scanf("%lf %lf", &Array[1].x, &Array[1].y);
     scanf("%lf %lf", &Array[2].x, &Array[2].y);
     scanf("%lf %lf", &Array[3].x, &Array[3].y);    
 
    R1 = Find(1, 2);
    R2 = Find(1, 3);
 
    if (R1.A==R2.A && R1.B == R2.B){
        printf ("No\n");
        return 0; 
    }
    
    double ang1 = (Array[1].x-Array[2].x)*(Array[1].x-Array[2].x) + (Array[1].y-Array[2].y)*(Array[1].y-Array[2].y);
    double ang2 = (Array[3].x-Array[2].x)*(Array[3].x-Array[2].x) + (Array[3].y-Array[2].y)*(Array[3].y-Array[2].y);
   
 
   
    if (fabs(ang1-ang2) < EPS) printf ("Yes\n");
     else printf ("No\n"); 
 
    return 0;   
 }