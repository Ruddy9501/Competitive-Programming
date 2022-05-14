/*
2017-09-27 22:31:03
https://codeforces.com/contest/854/problem/E
*/
#include <bits/stdc++.h>
 
using namespace std;
const int RAN = 5e6 + 5;
int c, n, q, x_, y_, x, y;
int C[RAN], S[10][200005]; 
long long s[RAN];
 
struct evento{
       int x, id, y_, y, p, p1;
       bool operator<(const evento &R)const{
       	     if (x != R.x) return x < R.x;
       	     return id < R.id;
       }
}E[RAN];
 
void update(int p){
     for (int i = p; i < RAN; i += (i & -i))
          C[i]++; 
}
 
int query(int p){
	int sum = 0;
	for (int i = p; i > 0; i -= (i & -i))
         sum += C[i];
    return sum;      
} 
 
int main(){
 
    scanf ("%d%d", &n ,&q);
    for (int i = 0; i < n; i++){
    	 scanf ("%d", &x);
    	 E[c++] = evento{i+1, 1, x, 0, 0};
    }
 
    for (int i = 0; i < q; i++){
    	 scanf ("%d %d %d %d", &x_, &y_, &x, &y);
    //	 E[c++] = evento{x_, 0, y_, y, i};
    //	 E[c++] = evento{x, 2, y_, y, i};
         s[i] = 1ll * n*(n-1ll)/2ll; 
    	 E[c++] = evento{x_-1, 2,  0,   n, i, 1};
    	 E[c++] = evento{   n, 2,  0,y_-1, i, 2};
    	 E[c++] = evento{   n, 2,y+1,   n, i, 3};
    	 E[c++] = evento{ x+1, 0,  0,   n, i, 4};
    	 E[c++] = evento{   n, 2,  0,   n, i, 4};
    	 E[c++] = evento{x_-1, 2,  0,y_-1, i, 5};
    	 E[c++] = evento{   0, 0,y+1,   n, i, 6};
    	 E[c++] = evento{x_-1, 2,y+1,   n, i, 6};
    	 E[c++] = evento{ x+1, 0,  0,y_-1, i, 7};
    	 E[c++] = evento{   n, 2,  0,y_-1, i, 7};
    	 E[c++] = evento{ x+1, 0,y+1,   n, i, 8};
    	 E[c++] = evento{   n, 2,y+1,   n, i, 8};
    }
 
    sort (E, E+c);
 
    for (int i = 0; i < c; i++){
    	 //printf ("%d %d\n", E[i].id, E[i].x);
    	 if (E[i].id == 1){
    	 	 update (E[i].y_);
    	 	 continue;
    	 }
 
    	 if (E[i].id == 0){
    	 	 S[E[i].p1][E[i].p] -= (query(E[i].y) - query(E[i].y_ - 1));
    	 	 //printf ("---- %d %d %d %d %d\n", E[i].p, E[i].x, E[i].y_, E[i].y, (query(E[i].y) - query(E[i].y_ - 1)));
    	 	 continue;
    	 }
 
    	 S[E[i].p1][E[i].p] += (query(E[i].y) - query(E[i].y_ - 1));
    	  //printf ("++++ %d %d %d %d %d\n", E[i].p, E[i].x, E[i].y_, E[i].y, (query(E[i].y) - query(E[i].y_ - 1)));
    	 	
    }
    
    for (int i = 0; i < q; i++){
    	 for (int j = 1; j < 5; j++){
    	 	//  printf ("%d ", S[j][i]);
    	 	  s[i] -= 1ll * S[j][i]*(S[j][i]-1ll)/2ll;
    	 }
    	 for (int j = 5; j < 9; j++){
    	 	  s[i] += 1ll * (S[j][i]*(S[j][i]-1ll)/2ll);
    	 }
    }
 
    for (int i = 0; i < q; i++)
    	 printf ("%lld\n", s[i] );
    
 
    return 0;
}