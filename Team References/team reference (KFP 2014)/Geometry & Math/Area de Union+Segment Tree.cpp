# include <cstdio>
# include <algorithm>
# define RANG 55000
# define oo 20000

using namespace std;

struct ct{
	int x1, y1, x2, y2;
	ct(int a=0, int b=0, int c=0, int d=0){
	   x1 = a; y1 = b; x2 = c; y2 = d;
	}
}A[1005];

struct par{
	int x, e, p;
	par(int a=1, int b=1, int c=1){
		x = a, e = b, p = c;
	}
}event[2005];

struct cmp_x{
	bool operator () (const par &a, const par &b)const{
		return a.x < b.x;
	}
};
int a, b, n, i, x, y, z, w, sol;
int T[RANG*3+5], mk[RANG*3+5];

int update(int V, int x=1, int xend=RANG, int P=1){
	if(b < x || xend < a)
	   return T[P];

	if(a <= x && xend <= b){
		mk[P] += V;
		if(!mk[P]){
			if(x == xend)T[P] = 0;
			else T[P] = T[P*2]+T[P*2+1];
		}
		else T[P] = xend-x+1;
	}
	if(x == xend)
	   return T[P];
	int pv = (x+xend)/2;
	return T[P] = update(V, x, pv, P*2) + update(V, pv+1, xend, P*2+1);
}

int main(){

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %d %d %d", &x, &y, &z, &w);
		A[i] = ct(x+oo, w+oo, z+oo, y+oo);
		event[i*2] = par(x+oo, 1, i);
		event[i*2+1] = par(z+oo, -1, i);
	}

	sort(event, event+2*n, cmp_x());

	for(i = 0; i < 2*n; i++){
		sol += T[1]*(event[i].x-event[i-1].x);
		a = A[event[i].p].y1;
		b = A[event[i].p].y2-1;
		update(event[i].e);
	}

	printf("%d", sol);

	return 0;
}
