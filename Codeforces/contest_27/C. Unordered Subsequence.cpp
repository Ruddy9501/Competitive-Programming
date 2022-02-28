/*2016-04-05*/
#include <bits/stdc++.h>
 
using namespace std;
 
int n, p, c;
int M[1000000], s, S[1000000], a[1000000];
bool mar1, mar2;
 
struct par{
       int v, id;
       bool operator<(const par &R)const{
            if (R.v != v) return R.v < v;
            return R.id < id;
       }
}A[1000000];
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
 
    cin >> n;
    for (int i = 1; i <= n; i++){
         cin >> a[i];
         A[i].id = i;
         A[i].v = a[i];
    }
 
 
    for (int i = 1; i < n; i++){
         if (a[i] < a[i+1])mar1=true;
         if (a[i] > a[i+1])mar2=true;
    }
 
    if (!mar1||!mar2) cout << "0\n";
     else{
         cout <<"3\n";
       sort(A+1,A+n+1);
       for (int i = 1; i < n; i++){
            if (A[i].id-A[i+1].id  > 1 && A[i+1].v != a[A[i+1].id+1]){
                cout << A[i+1].id << " " << A[i+1].id+1<<" "<<A[i].id<<"\n";
                break;
            }
            if (A[i].id-A[i+1].id  < -1&& A[i].v != a[A[i].id+1]){
                cout << A[i].id << " "<<A[i].id+1<<" "<<A[i+1].id<<"\n";
                break;
            }
       }
     }
 
 
 
    return 0;
}