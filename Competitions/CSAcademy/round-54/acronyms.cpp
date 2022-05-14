#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
int n, sol, c[30];
char b[10*MAX];
string a[MAX];

int main(){
    
    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
    	 scanf ("%s", b);
    	 int la = strlen (b);
    	 string s = "";
    	 for (int j = 0; j < la; j++)
    	 	  s += b[j];
    	 a[i] = s;	
    	 c[b[0]-'a']++;
    }
    
    for (int i = 0; i < n; i++){
         c[a[i][0]-'a']--;
         int la = (int)a[i].size();
         bool mar = true;
         for (int j = 0; j < la; j++){
         	  if (c[a[i][j]-'a'] <= 0) mar = false;
         	  c[a[i][j]-'a']--;
         } 
         
         for (int j = 0; j < la; j++)
         	  c[a[i][j]-'a']++;
         
         c[a[i][0]-'a']++;

         if (mar) sol++;
    }

    printf ("%d\n", sol);

	return 0;
}