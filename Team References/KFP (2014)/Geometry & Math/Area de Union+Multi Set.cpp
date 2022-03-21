# include <set>
# include <cmath>
# include <cstdio>
# include <algorithm>
# define oo 1 << 29
using namespace std;

struct par{
	int x1, y1, x2, y2;
	par (int a=0, int b=0, int c=0, int d=0){
	 x1=a, y1=b, x2=c, y2=d;
	}
}A[1005];

struct tri {
	int x, e, p;
	tri (int a = 0, int b = 0, int c = 0){
		x = a, e = b, p = c;
	}
	bool operator < (const tri &a)const{
		return x < a.x;
	}
}S[2005];

struct par1{
	int y, e;
	par1(int a = 0, int b = 0){y = a, e = b;}
};

struct cmp_y{
	 bool operator () (const par1 &a, const par1 &b)const{
		return a.y < b.y;
	}
};

multiset <par1, cmp_y> M;
multiset <par1, cmp_y>::iterator lo;

int n, x, y, z, w, L, l, i, s;
long long amount, sol;

int main(){

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %d %d %d", &x, &y,&z, &w);
		A[i] = par(x, y, z, w);
		S[2*i] = tri(x, 1, i);
		S[2*i+1] = tri(z, -1, i);
	}

	sort(S, S+2*n);
	amount = 0;

	for(i = 0; i <= 2*n; i++){

		if(S[i].e == -1){
			M.erase(M.find((par1){A[S[i].p].y1, 1}));           
			M.erase(M.find((par1){A[S[i].p].y2, -1}));
		}
		else {
			M.insert((par1){A[S[i].p].y1, 1});
			M.insert((par1){A[S[i].p].y2, -1});
		}

		sol += amount*(long long )abs(S[i].x-S[i-1].x);

		amount = 0;
		for(lo = M.begin(); lo != M.end(); lo++){// amount
			if(s == 0)
			   l = lo->y;
			s += lo->e;
			if(s == 0){
				amount += (lo->y-l);
			}
		}
	}

	printf("%lld", sol);
	return 0;
}
