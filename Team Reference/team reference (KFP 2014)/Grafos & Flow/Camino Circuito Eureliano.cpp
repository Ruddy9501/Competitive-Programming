# include <queue>
# include <vector>
# include <cstdio>

using namespace std;

struct tri{
   int np, nh;
   bool mk;

   int next(int x){
       if(x == np)
           return nh;
       return np;
   }
}A[5005];

int ini = 1, i, j, x, y, c, cn, cc, C[5005];
vector <int> v[5005];
queue <int> Q;

void Euler(int np){
    int ls = v[np].size();
    for(int i = 0; i < ls; i++){
        int p = v[np][i];
        if(!A[p].mk){
           A[p].mk = true;
           Euler(A[p].next(np));
       }
   }
   Q.push(np);
}

int main(){

    scanf("%d %d", &cn, &cc);
    for(i = 1; i <= cc; i++){
        scanf("%d %d", &x, &y);
        A[i] = (tri){x, y, false};
        v[x].push_back(i);
        v[y].push_back(i);
        C[x]++;
        C[y]++;
    }

	for(i = 1; i <= cn; i++)
        if(C[i] % 2 == 1)
            c++,
            ini = i;

    if(c > 2){
        printf("No es camino, ni circuito");
        return 0;
    }
	
    if(c == 2)
        printf("Es camino\n");
	
    if(c == 0)
        printf("Es circuito\n");

    Euler(ini);

    for(;!Q.empty(); Q.pop())
        printf("%d\n", Q.front());
	
	return 0;
 }
