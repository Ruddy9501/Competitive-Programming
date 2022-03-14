# include <queue>
# include <cstdio>
# include <vector>
# include <algorithm>
# define oo 1 << 29

using namespace std;

int sr, sk, n, m, x, y, z, np, nh, cp, p, l, i, max_flow, b;
int Flow[105][105], Fr[105];
bool mk[105];

vector <int> v[105];

int aug_path(){
	priority_queue <pair<int, int> > Q;

	fill(Fr, Fr+n+1, -1);
	fill(mk, mk+n+1, false);
	mk[sr] = true;
	Q.push(make_pair(oo, sr));
	b = 0;

	while(!Q.empty()){
		cp = Q.top().first;
		np = Q.top().second;
		Q.pop();

		if(np == sk){
				b = max(b, cp);
			break;
		}

		l = v[np].size();
		for(i = 0; i < l; i++){
			nh = v[np][i];
			if(!mk[nh] && Flow[np][nh]){
				mk[nh] = true;
				Fr[nh] = np;
				Q.push(make_pair(min(cp, Flow[np][nh]), nh));
			}
		}
	}

	nh = sk;
	while(Fr[nh] != -1){
		np = Fr[nh];
		Flow[np][nh] -= b;
		Flow[nh][np] += b;
		v[nh].push_back(np);
		nh = np;
	}

	return b;
}

int main(){

	scanf("%d %d %d %d", &n, &m, &sr, &sk);
	
	for(i = 1; i <= m; i++){
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(y);
		Flow[x][y] = z;
	}

	//while(p = aug_path()) max_flow += p;
	max_flow = aug_path();
	printf("%d\n", max_flow);
	
	return 0;
}
