#include <bits/stdc++.h>

using namespace std;

int x[10], y[10], A[10];

long long dis(int i, int j){
     long long a =x[i]-x[j];  
     long long b =y[i]-y[j];  
     return  a*a + b*b;
}

int main(){
    
    int cas;scanf ("%d", &cas);
    while (cas--){
    	   for (int i = 0; i < 4; i++)
    	   	    scanf ("%d %d", &x[i], &y[i]);
           A[0] = 0, A[1] = 1, A[2] = 2, A[3] = 3;
           bool mar = false;
           do{
              if (dis(0, 2) == dis(1, 3)) mar = true;

           }while (next_permutation(A, A+4));
    
           if (mar) printf("1\n");
            else printf ("0\n"); 
    }



    return 0;
}