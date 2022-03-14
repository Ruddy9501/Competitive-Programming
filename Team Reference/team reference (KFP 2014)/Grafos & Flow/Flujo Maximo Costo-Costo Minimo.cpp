# include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;

struct nod{
        ll x,y,h;
        int id;
}N[505];

vector<int> v[505];

ll dist(nod a,nod b){
        if(a.id == 0 || b.id == 0 || a.id == n+1 || b.id == n+1)return 0;
        return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) + (b.h - a.h)*(b.h - a.h);
}

int cap[505][505],tipo[505];
double costo[505][505],res;
vector<int> ady[505];
int from[505];
double d[505];

struct nodo{
        int id,parent;
        double costo;
        bool operator<(const nodo& a)const{
            return costo > a.costo;
        }
};

bool town[505];
double cost[505];
bool visited[505];
bool spring[505];
int s,t,cn;
double valor[505][505];

int augment1(int source, int sink){
	
	fill(from,from+sink+1,-1);
	fill(d,d+sink+1,99999999.0);
	fill(mk,mk+sink+1,0);
	
	d[source] = 0;
	bool x = 0;
	bool y = 0;
	
	for(int i = 1; i <= cn; i++){
		for(int h = 0; h < cn ; h++){
			int no = tipo[h];
			int len = v[no].size();
			for(int k = 0; k < len; k++){
				int m = v[no][k];
				if(cap[no][m] && d[m] > d[no] + costo[no][m]){
					d[m] = d[no] + costo[no][m];
					from[m] = no;
					y = 1;
					if(m == sink)x = 1;
				}
			}
		}
		if(!y)break;
	}
	
	if(!x)return 0;
	
	int actual = sink;
	res+=d[sink];

	while(from[actual]!=-1){
		 cap[actual][from[actual]]++;
		 cap[from[actual]][actual]--;
		 actual = from[actual];
	}
	return 1;
}

int max_flow(int sink,int source){
        int r = 0;
        while(1){
            if(augment1(sink,source))r++;
            else return r;
        }
}

int main(){
	
    int a;
    ll q;
	
    scanf("%d %d %d %I64d",&n,&s,&t,&q);
	
    N[0].id = 0;
    N[n+1].id = n+1;
	
    for(int i = 1; i <= n; i++){
        scanf("%I64d %I64d %I64d",&N[i].x,&N[i].y,&N[i].h);
        N[i].id = i;
        for(int h = 1; h < i; h++){
               // cout<<"d "<<dist(N[i],N[h])<<endl;
		    ll g = dist(N[i],N[h]);
		    valor[i][h] = valor[h][i] = sqrt((double)g);
			
            if(g <= q*q && N[i].h > N[h].h){
                ady[i].push_back(h);
            }
			
            if(g <= q*q && N[i].h < N[h].h){
                ady[h].push_back(i);
            }
        }
    }
	
    for(int i = 0; i < s; i++){
        scanf("%d",&a);
        tipo[++cn] = a;
        cap[0][a] = 1;
        v[0].push_back(a);
        spring[a] = 1;
    }
	
    for(int i = 0; i < t; i++){
        scanf("%d",&a);
        cap[a][n+1] = 1;
        v[a].push_back(n+1);
        town[a] = 1;
        tipo[++cn] = a;
    }
	
    cn++;
    tipo[cn] = n+1;
    for(int i = 1; i <= n; i++){
        if(spring[i]){
            dijkstra(i);
        }
    }
	
    int k = max_flow(0,n+1);
	
    if(k < t)printf("IMPOSSIBLE\n");
    else{
        printf("%lf\n",res);
    }
	
    return 0;
}
