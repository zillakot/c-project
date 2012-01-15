#include <stdio.h>
#include <math.h>

typedef struct{
	double x;
	double y;	
} Point;

Point averages(Point *point, int n, Point *stdev);

int main(void){
    
    int n=10;
	int i;

	Point points[n];
	Point stdev;
	Point average;
    
    for(i = 0; i < n; i++){
		points[i].x = i+1;
		points[i].y = (i+1)*(i+1);
		printf("%f %f\n", points[i].x, points[i].y);
    }

	average=averages(points, n, &stdev);
	
	printf("\n%f\n",average.x);
	printf("%f\n",average.y);
	printf("%f\n",stdev.x);
	printf("%f\n",stdev.y);

    return 0;
}

Point averages(Point *point, int n, Point *stdev) {
	Point avg, sq_avg;
	
    int i;

	avg.x=0;
	avg.y=0;
	sq_avg.x=0;
	sq_avg.y=0;

    for (i=0; i<n; i++) {
    	avg.x=avg.x+point[i].x;
		avg.y=avg.y+point[i].y;
		sq_avg.x=sq_avg.x+point[i].x*point[i].x;
		sq_avg.y=sq_avg.y+point[i].y*point[i].y;
    }

	/*Average*/
	avg.x=avg.x/n;
	avg.y=avg.y/n;
	
	/*Variation*/
	sq_avg.x = sq_avg.x/(n-1) - (avg.x*avg.x*n)/(n-1);
	sq_avg.y = sq_avg.y/(n-1) - (avg.y*avg.y*n)/(n-1);
	
	/*Standard deviation*/
	stdev->x = sqrt(sq_avg.x);
	stdev->y = sqrt(sq_avg.y);
	
    return avg;
}