# include <set>
# include <cstdio>
# include <cmath>
# include <algorithm>
using namespace std;

struct par {
	double x, y;
}a[5005], *l = &a[0];

struct cmp_x{
	bool operator () (const par &a, const par &b)
	const {
		return a.x < b.x;
	}
};

struct cmp_y{
	bool operator () (const par &a, const par &b)
	const {
		return a.y < b.y;
	}
};


double dist(par a, par b){
	return (double) sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

int n;
double sol = 1 << 29;
multiset <par, cmp_y> Q;
multiset <par, cmp_y>::iterator lo, hi;

int main(){

	fscanf(fe, "%d", &n);
	for(int i = 0; i < n; i++)
		fscanf(fe, "%lf %lf", &a[i].x, &a[i].y);

	sort(a, a+n, cmp_x());

	for(par *i = &a[0]; i != &a[n]; i++){
		while(i -> x - l -> x >= sol)
			Q.erase( Q.find(*l++) );

		lo = Q.lower_bound( 
	(par) {i->x, i->y-sol} );
		hi = Q.upper_bound(
	(par) {i->x, i->y+sol} );


		for(; lo != hi; lo++)
			sol = min(sol, dist(*lo, *i));

		Q.insert(*i);
	}

	fprintf(fs, "%.2lf", sol);
	return 0;
}
