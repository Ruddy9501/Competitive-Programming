# include <cstdio>
using namespace std;

int cn, cc, i, j, k, x, y, z;
int map[305][305];

int main(){

	scanf("%d %d", &cn, &cc);
	for(i = 1; i <= cc; i++){
		scanf("%d %d %d", &x, &y, &z);
		if(map[x][y] == 0 || map[x][y] > z)
			map[x][y] = z;
		if(map[y][x] == 0 || map[y][x] > z)
			map[y][x] = z;
	}

	for(k = 1; k <= cn; k++)
	for(i = 1; i <= cn; i++)
		if(map[i][k] > 0){
		   for(j = 1; j <= cn; j++){
			   if(map[k][j] == 0)
				  continue;
			   if(map[i][j] == 0 || map[i][j] > map[i][k]+map[k][j])                        
				  map[i][j] = map[i][k]+map[k][j];
			}
			}

	for(i = 1; i <= cn; i++){
		for(j = 1; j <= cn; j++)
			if(map[i][j] == 0)
				printf("? ");
			else
				printf("%d ", map[i][j]);
		printf("\n");
	}
}
