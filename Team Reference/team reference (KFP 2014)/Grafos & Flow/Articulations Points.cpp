# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;

vector <int> v[505];
int low[505], D[505], x, y, cn, cc, l;
bool mk[505];

void Apoint(int node){
low[node] = D[node] = ++l;
int ls = v[node].size();
for(int i = 0; i < ls; i++){
	int next = v[node][i];
	if(!low[next]){
		Apoint(next);
		low[node] = min(low[node], low[next]);
		if( (D[node] == 1 && D[next] > 2) ||
			(low[next] >= D[node] && D[node] != 1) )
			mk[node] = true;
	}
	else
		low[node] = min(low[node], D[next]);
}
}
int main(){

scanf("%d %d", &cn, &cc);
for(int i = 1; i <= cc; i++){
	scanf("%d %d", &x, &y);
	v[x].push_back(y);
	v[y].push_back(x);
}

Apoint(1);

for(int i = 1; i <= cn; i++)
	if(mk[i])
		printf("%d\n", i);
}
