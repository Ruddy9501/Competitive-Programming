//~ 446E - codeforces (Union-Find + Rollback)
/* You are given a graph G. You are given
 * some queries, each query contains a set
 * of edges of graph G, and you should
 * determine whether there is a MST
 * containing all these edges or not.
 */
#include <bits/stdc++.h>
using namespace std;

#define fr first
#define sc second

struct UF
{
	int n;
	vector<int> root, r;
	vector<pair<int&,int>> ops;
	UF(int n)
	:root(n+1),r(n+1,1)
	{
		for(int i=1;i<=n;++i)root[i]=i;
	}
	
	int fs(int u)
	{
		while(root[u]!=u)u=root[u];
		return u;
	}
	void modify(int &a,int b)
	{
		ops.emplace_back(a,a);
		a=b;
	}
	bool js(int u,int v)
	{
		u=fs(u),v=fs(v);
		if(u==v)return false;
		if(r[u]<r[v])
			swap(u,v);
		
//		ops.emplace_back(u,v);
		
		modify(root[v],u);
		modify(r[u],r[u]+r[v]);
/*
		r[u]+=r[v];
		root[v]=u;
*/
		return true;
	}
	void rb(int bot)
	{ // rollback technique
		while(ops.size() > bot)
		{
			ops.back().fr = ops.back().sc;
			ops.pop_back();
/*
			PII cur=ops.back();
			
			r[cur.fr]-=r[cur.sc];
			root[cur.sc]=cur.sc;

			ops.pop_back();
*/
		}
	}
};

const int N = 5e5+7;

struct query
{
	int u,v,w,id;
	query(int u,int v,int w,int id)
	:u(u),v(v),w(w),id(id){}
	bool operator<(const query &o)const
	{
		if(w!=o.w)return w<o.w;
		return id<o.id;
	}
};

int n,m;
vector<query> qe;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%d%d%d", &u, &v, &w);
		qe.emplace_back(query(u,v,w,N));
	}
	
	int q;cin >> q;
	for(int j=1;j<=q;++j)
	{
		int k; scanf("%d", &k);
		for(int i=1;i<=k;++i)
		{
			int p;scanf("%d", &p);
			qe.emplace_back(query(qe[p-1].u,qe[p-1].v,qe[p-1].w,j));
		}
	}

	sort(qe.begin(),qe.end());
/*
	for(auto x: qe)
		cerr << x.w << ' ' << x.id << ' ' << x.u << ' ' << x.v << endl;
*/
	UF uf(n);
	vector<int> ans(q+1,1);
	for(int i=0,j;i<qe.size();i=j)
	{
		j=i;
		int cq=qe[j].id;

//		cerr << " A " << j << endl;

		if(cq == N)
		{
			do
			{
//				cerr << " bad " << j << '\n';
				uf.js(qe[j].u,qe[j].v);
				++j;
			}while(j < qe.size() && qe[j].w == qe[j-1].w
        && qe[j].id == qe[j-1].id);
		}else
		{
			int sback=uf.ops.size();
			bool flag=true;
			do
			{
				if(!flag){++j;continue;}
//				cerr<<" good " << j << '\n';
				if(!uf.js(qe[j].u,qe[j].v))
				{
					ans[qe[j].id] &= 0;
					flag=false;
					++j;
					continue;
				}
				++j;
			}while(j < qe.size() && qe[j].w == qe[j-1].w
        && qe[j].id == qe[j-1].id);
			uf.rb(sback);
		}
	}
	
	for(int i=1;i<=q;++i)
		if(ans[i]) printf("YES\n");
		else printf("NO\n");

	return 0;
}
