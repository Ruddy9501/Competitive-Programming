/* Vantage point Tree
 * testeado en http://coj.uci.cu/24h/problem.xhtml?pid=1914
 * 
 * Consider having N (1 <= N <= 10^4) points in the 2D space.
 * You will be queried with Q (1 <= Q <= 10^4) circles and you
 * need print how many of the given points are inside the circle.
 */
#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;

namespace std
{
	bool operator <(point p, point q)
	{
		if (real(p) != real(q))
			return real(p) < real(q);
		return imag(p) < imag(q);
	}
}

struct vantage_point_tree
{
	struct node
	{
		point p;
		int can;
		double th;
		node *l, *r;
	}*root;

	vector<pair<double, point>> aux;

	vantage_point_tree(vector<point> ps)
	{
		for (int i = 0; i < ps.size(); ++i)
			aux.push_back({ 0, ps[i] });
		root = build(0, ps.size());
	}

	node *build(int l, int r)
	{
		if (l == r)
			return 0;
		swap(aux[l], aux[l + rand() % (r - l)]);
		point p = aux[l++].second;
		if (l == r)
			return new node({ p });
		for (int i = l; i < r; ++i)
			aux[i].first = norm(p - aux[i].second);
		int m = (l + r) / 2;
		nth_element(aux.begin() + l, aux.begin() + m, aux.begin() + r);
		return new node({ p, m-l, sqrt(aux[m].first), build(l, m),
      build(m, r) });
	}

	int k_nn(node *t, point p, int k)
	{
		if (!t)
			return 0;

		double d = sqrt (norm (p - t->p));

        int a = 0;

		if (k >= d + t -> th)
            a = t -> can + 1;
         else
            if (d <= k + t -> th)
                a = k_nn (t->l, p, k) + (d <= k);

		int b = k_nn (t->r, p, k);
		return a+b;
	}

	int k_nn (point p, int k){
		return k_nn(root, p, k);
	}
};

int x, y, r;

int main(){

    int n, m;scanf ("%d%d", &n, &m);
    vector <point> v;
    for (int i = 1; i <= n; ++i){
         scanf ("%d%d", &x, &y);
         v.push_back ({x, y});
    }

    vantage_point_tree vp (v);
    for (int i = 1; i <= m; ++i){
         scanf ("%d%d%d", &x, &y, &r);
         point p1 = {x, y};
         int p = vp.k_nn (p1, r);
         printf ("%d\n", p);
    }

    return 0;
}
