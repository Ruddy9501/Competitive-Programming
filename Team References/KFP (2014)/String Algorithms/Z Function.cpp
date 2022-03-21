// En cada posicion de z[i] esta guardado el tamaño 
// del mayor sufijo que es prefijo 
// de la palabra y empieza en "i".
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

int i, l, r, ls, z[5005];
char s[5005];
int main(){
	scanf("%s", &s);
	ls = strlen(s);

	for (int i = 1, l = 0, r = 0; i < ls; ++i){
		if (i <= r)
			z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < ls && 
		       s [z[i]] == s [i + z[i]])
			++z[i];
	    if (i + z[i] - 1> r)
			l = i, r = i + z[i] - 1;
	}
	 
	for(i = 0; i < ls; i++)
		printf("%d ", z[i]);
	
	return 0;
}
