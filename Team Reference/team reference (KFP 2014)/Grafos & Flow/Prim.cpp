# include <queue>
# include <vector>
# include <cstdio>
using namespace std;

struct par {
	int n1, n2;
	bool operator < (const par &a)
	const {
		return n2 > a.n2;
	}
};

bool mk[5005];
int np, nh, nc, ch, i, l, x, y, z, sol, cn, cc;
vector <par> v[5005];
priority_queue <par> Q;

int main(){

	scanf("%d %d", &cn, &cc);
	
	for(i = 1; i <= cc; i++){
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back((par){y, z});
		v[y].push_back((par){x, z});
	}
	
	for(Q.push((par){1, 0}); 
		!Q.empty(); 
		Q.pop()){

		np = Q.top().n1;
		nc = Q.top().n2;
		l = v[np].size();

		if(mk[np])continue;
		mk[np] = true;
		sol += nc;

		for(i = 0; i < l; i++){
			nh = v[np][i].n1;
			ch = v[np][i].n2;
			if(!mk[nh])
				Q.push((par){nh, ch});
		}
	}

	printf("%d", sol);
	
	return 0;
}
