#include <stdio.h>
#include <math.h>

typedef struct{
	double x;
	double y;	
} Point;

int main(void){
    
    int n=100;
	int i;

	Point points[n];
	Point stdev;
	Point average;
    
    for(i = 0; i < n; i++){
		points[i].x = i;
		points[i].y = cos(i);
		printf("%f %f\n", points[i].x, points[i].y);
    }

	average=averages(points, n, &stdev);
	
	printf("\n%f\n",average.x);
	printf("%f\n",average.y);
	printf("%f\n",stdev.x);
	printf("%f\n",stdev.y);

    return 0;
}