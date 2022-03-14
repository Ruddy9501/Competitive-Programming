# include <queue>
# include <cstdio>
using namespace std;

int R[5005], Set[5005];
int i, x, y, z, n1, n2, sol, cn, cc;

struct par{
	int x, y, z;
	bool operator < (const par &a)
	const {
		return z > a.z;
	}
};

priority_queue <par> Q;

void make_set(){
	for(int i = 1; i <= cn; i++)
		R[i] = 1, Set[i] = i;
}

int find_set(int x){
	if(x != Set[x])
		return Set[x] = find_set(Set[x]);
	return x;
}

void join_set(){
	if(R[n1] > R[n2])
		Set[n2] = n1, R[n1] += R[n2];
	else
		Set[n1] = n2, R[n2] += R[n1];
}

int main(){

	freopen("kruskal.in", "r", stdin);
	freopen("kruskal.out", "w", stdout);

	scanf("%d %d", &cn, &cc);
	for(i = 1; i <= cc; i++){
		scanf("%d %d %d", &x, &y, &z);
		Q.push((par){x, y, z});
	}

	make_set();
	for(; !Q.empty(); Q.pop()){
		n1 = find_set(Q.top().x);
		n2 = find_set(Q.top().y);
		if(n1 != n2)
			sol += Q.top().z,
			join_set();
	}
	
	printf("%d", sol);
	
	return 0;
}
