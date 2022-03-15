//testeado en http://coj.uci.cu/24h/problem.xhtml?pid=2067 (City Houses)
/* Compute for each house, the minimum distance
 * to any of the other houses (Manhattan distance)
 */
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>
using namespace std;
typedef long long i64;
const int MAX = 1e5 + 10;
#define sqr(x) (abs(x))
struct point {
	int x, y;
} data[MAX], d[MAX];
inline bool cmpx(const point& a, const point& b) {
	return a.x < b.x;
}

inline bool cmpy(const point& a, const point& b) {
	return a.y < b.y;
}
inline i64 dist(const point& point1, const point& point2) {
	return abs(point1.x - point2.x) + abs(point1.y - point2.y);
}

int cant[4*MAX];
void Create2DTree(int index, int left, int der, bool h = 1) {
	cant[index] = der - left + 1;
	if (der - left + 1 <= 1)	return;
	int med = (left + der + 1) / 2;
	nth_element(data + left, data + med,
    data + der + 1, h ? cmpx : cmpy);
	Create2DTree(2 * index, left, med - 1, h ^ 1);
	Create2DTree(2 * index + 1, med + 1, der, h ^ 1);
}

point que;
i64 best;
void query(int index, int left, int der, int h) {
	if (cant[index] <= 0) return;

	int m = (left + der + 1) / 2;

	if (dist (data[m], que))
        best = min(best, dist(data[m], que));

	if (cant[index] == 1)return;

	if (!(h & 1)) {
		bool dir = cmpx(que, data[m]);
		if (dir) {
			query(2 * index, left, m - 1, h + 1);
			if (best >= sqr(que.x - data[m].x))
				query(2 * index + 1, m + 1, der, h + 1);
		} else {
			query(2 * index + 1, m + 1, der, h + 1);
			if (best >= sqr(que.x - data[m].x))
				query(2 * index, left, m - 1, h + 1);
		}
	} else {
		bool dir = cmpy(que, data[m]);
		if (dir) {
			query(2 * index, left, m - 1, h + 1);
			if (best >= sqr(que.y - data[m].y))
				query(2 * index + 1, m + 1, der, h + 1);
		} else {
			query(2 * index + 1, m + 1, der, h + 1);
			if (best >= sqr(que.y - data[m].y))
				query(2 * index, left, m - 1, h + 1);
		}
	}
}

int main() {
	int n, q; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &data[i].x, &data[i].y);
		d[i] = data[i];
    }

	Create2DTree(1, 1, n);
	q = n;
	for (int i = 1; i <= n; ++i) {
		best = LLONG_MAX;
		que = d[i];
		query(1, 1, n, 0);
		printf("%lld\n", (best));
	}
}


