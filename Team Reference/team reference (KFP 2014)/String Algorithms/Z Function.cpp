/// En cada posicion de Z[i] esta guardado el tamaño del mayor sufijo
/// que es prefijo de la palabra y empieza en "i".
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

int i, l, r, ls, Z[5005];
char s[5005];
int main(){
	scanf("%s", &s);
	ls = strlen(s);

	for (int i = 1, l = 0, r = 0; i < ls; ++i) {
		if (i <= r)
			Z[i] = min (r - i + 1, Z[i - l]);
		while (i + Z[i] < ls && s [ Z[i] ] == s [i + Z[i]])
			++Z[i];
	    if (i + Z[i] - 1> r)
			l = i, r = i + Z[i] - 1;
	}
	 
	for(i = 0; i < ls; i++)
		printf("%d ", Z[i]);
	
	return 0;
}
