//~ testado en http://codeforces.com/contest/892/problem/E
struct UF
{
	int n;
	vector<int> root, r;
	vector<PII> ops;
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
	bool js(int u,int v)
	{
		u=fs(u),v=fs(v);
		if(u==v)return false;
		if(r[u]<r[v])
			swap(u,v);
		
		ops.emplace_back(u,v);
		
		r[u]+=r[v];
		root[v]=u;
		return true;
	}
	void rb(int steps)
	{ // rollback technique
		while(steps--)
		{
			PII cur=ops.back();
			
			r[cur.fr]-=r[cur.sc];
			root[cur.sc]=cur.sc;

			ops.pop_back();
		}
	}
};

