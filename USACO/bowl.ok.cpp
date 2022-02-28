#include <cstdio>
#include <algorithm>
#define MAX 500

using namespace std;
typedef pair<int, int>par;

int n, sol, k, c;
int B[MAX][MAX], A[MAX][MAX];

int main (){
    
    freopen("bowl.in","r",stdin);
    freopen("bowl.out","w",stdout);   	
    
    scanf("%d\n",&n);
    
    for(int i = 1; i <= n; i++){
        k++;
        for(int j = 1; j <= k; j++){
           scanf("%d",&A[i][j]);
           A[i][j] += max(A[i-1][j], A[i-1][j-1]); 
           if(A[i][j] > sol)
              sol = A[i][j];
           }c++; 
    } 
    
    printf("%d\n",sol);
    
    return 0;  
    }

