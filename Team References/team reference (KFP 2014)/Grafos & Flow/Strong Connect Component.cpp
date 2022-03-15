# include <stack>
# include <vector>
# include <cstdio>
# include <algorithm>
using namespace std;

int T[5005], low[5005], L;
int x, y, cn, cc;
vector <int> v[5005];
stack <int> S;
bool mk[5005];

void SCC(int np){
	T[np] = low[np] = ++L;
	int l = v[np].size();
	S.push(np);
	for(int i = 0; i < l; i++){
		int nh = v[np][i];
		if(!T[nh]){
			SCC(nh);
			low[np] = min(low[nh], low[np]);
		}
		else
			if(!mk[nh])
				low[np] = min(T[nh], low[np]);
	}

	if(low[np] == T[np]){
		while(S.top() != np){
			printf("%d ", S.top());
			mk[S.top()] = true;
			S.pop();
		}
		printf("%d\n", S.top());
		mk[S.top()] = true;
		S.pop();
	}
}

int main(){

	scanf("%d %d", &cn, &cc);
	for(int i = 1; i <= cc; i++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
	}

	for(int i = 1; i <= cn; i++)
		if(!mk[i])
			SCC(i);
	return 0;
}
