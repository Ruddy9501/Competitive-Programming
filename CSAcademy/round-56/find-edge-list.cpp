#include <bits/stdc++.h>

using namespace std;

int n, a, b;
vector <int> v[100005];

vector < pair<int, int> > s;
queue <int> q;
int c[100005];

int main(){
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
	     scanf ("%d", &a); q.push(i);
	     for (int j = 0; j < a; j++){
		      scanf ("%d", &b);
		      v[i].push_back (b);
		 }
	}
	
	
	while (!q.empty()){
	     int i = q.front();
	     q.pop(); 
	     while (c[i] < (int)v[i].size()){
		        int p = v[i][c[i]];
		        if (v[p][c[p]] != i) break ;
		        s.push_back ({i, p});
		        c[p]++;
		        c[i]++;
		        q.push(p);
		 }
	}
	
	for (int i = 1; i <= n; i++)
	     if (c[i] < (int)v[i].size()){
		     printf ("-1\n");
		     return 0;
		 }
		 
    for (int i = 0; i < (int)s.size(); i++)
         printf ("%d %d\n", s[i].first, s[i].second); 		 
	
    return 0;	
}
