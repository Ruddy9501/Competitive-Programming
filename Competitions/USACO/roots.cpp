#include <stdio.h>
#include <math.h>

main () {
    int i, j, l, goal, n;
    double x, y, frac, multiplier;
    
    freopen("roots.in","r",stdin);
    freopen("roots.out","w",stdout);
    scanf("%d",&l);
    scanf("%d", &goal);
    for (multiplier = 1.0, i = 0; i < l; i++)
	multiplier *= 10.0;
    frac = goal/multiplier;
    for(i=1; i<46000; i++){
	n = (i+frac) * (i+frac) + 0.5;
	j = sqrt ( (double) n);
	x = sqrt ( (double) n);
	x -= j;
	j = multiplier * x;
	if (j == goal)  {
	    printf("%d"\n,n);
	    break;
	}
    }
   
    return 0;
}
