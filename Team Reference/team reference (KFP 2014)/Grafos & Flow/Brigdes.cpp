# include <vector>
# include <cstdio>
# define RANG 5005

using namespace std;

struct par{
	int np, nh;
	bool mk;

	int next(int x){
		if(x == np)
			return nh;
		return np;
	}
}A[RANG];

int cc, i, L, x, y;
int Low[RANG], T[RANG];
vector <int> v[RANG];

void Brigdes(int np){
T[np] = Low[np] = ++L;
int l = v[np].size();

for(int i = 0; i < l; i++){
	int nh = A[ v[np][i] ].next(np);

	if(!T[nh]){
		A[ v[np][i] ].mk = true;
		Brigdes(nh);
		Low[np] = min(Low[nh], Low[np]);
		if(Low[nh] > T[np])
			printf("%d %d\n", np, nh);
	}
	else
		if(!A[v[np][i]].mk)
			Low[np] = min(Low[np], T[nh]);

}
}

int main(){

	scanf("%d", &cc);
	for(i = 1; i <= cc; i++){
		scanf("%d %d", &x, &y);
		A[i] = (par){x, y};
		v[x].push_back(i);
		v[y].push_back(i);
	}

	Brigdes(1);
	return 0;
}
