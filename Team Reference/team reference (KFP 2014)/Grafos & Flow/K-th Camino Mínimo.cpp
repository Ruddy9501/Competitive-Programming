# include <queue>
# include <vector>
# include <cstdio>
# define RANG 5005
using namespace std;

struct par {
	int x, y;
	bool operator > (const par &a)
	const {
		return y > a.y;
	}
};

vector <par> v[RANG];
priority_queue <par, vector<par>, greater<par> > Q;
int End, cc, i, x, y, z, np, nh, nc, hc, l, k;
int V[RANG];

int k_th(){

	for(Q.push((par){1, 0}); !Q.empty(); ){
		np = Q.top().x;
		nc = Q.top().y;
		Q.pop();
		l = v[np].size();
		V[np]++;

		if(np == End){
			if(V[np] == k)return nc;
		}

		for(i = 0 ; i < l; i++){
			nh = v[np][i].x;
			hc = v[np][i].y;
			if(V[nh] < k)
				Q.push((par){nh, nc+hc});
		}
	}
}

int main(){

	scanf("%d %d %d", &cc, &End, &k);
	for(i = 1; i <= cc; i++){
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back((par){y, z});
		v[y].push_back((par){x, z});
	}

	printf("%d", k_th());

	return 0;
}
