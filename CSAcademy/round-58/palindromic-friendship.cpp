#include <bits/stdc++.h>


using namespace std;

const int MAX = 2e5 + 5;
int n, m, a, b;
vector <int> v[MAX];
set <int> s[MAX];

bool ok(int a, int b){
	
     while (a < b){
	        if (s[a].find(b) == s[a].end()) return false;
	        a++, b--;
	 }
	 
	 return true;
}

int main(){
	
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
	     scanf ("%d %d", &a, &b);
	     v[a].push_back (b);
	     v[b].push_back (a);
	     s[a].insert (b);
	     s[b].insert (a);
	}
	
	
	
	int sol = 1; //printf ("%d\n", ok(1, 2));
	for (int i = 1; i <= n; i++){
	     a = i;
	     int l = (int)v[i].size();
	     sort (v[i].begin(), v[i].end());
	     reverse (v[i].begin(), v[i].end());
	     for (int j = 0; j < l; j++){
		      b = v[i][j];
		      if (sol < b-a+1){
			      if (ok(a, b))
			          sol = b-a+1;
			  }
		 }
	}
	
	printf ("%d\n", sol);
	
    return 0;	
}
