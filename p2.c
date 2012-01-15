#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	double x;
	double y;	
} Point;

int main(void){
    
    int n=100;
	int i,j;
	double x,y,k,b;
	double time1, timeDif;

	Point p[n];
    
	/* initialize random seed: */
	 srand ( time(NULL) );

    for(i = 0; i < n; i++){
		p[i].x = i * M_PI / 50.0;
		p[i].y = cos(p[i].x);
		printf("%f %f\n", p[i].x, p[i].y);
    }
	
	time1 = (double) clock();
	
	for(j=0; j<10000000; j++){
		
		x=rand()%100;
		x=fmod(fabs(x),2*M_PI);
	
		i=x*50/M_PI;
	
		k=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x);
		b=p[i].y-k*p[i].x;
	
		y=k*x+b;
	}
	
	
	timeDif = ((double) clock() - time1)/CLOCKS_PER_SEC;

	printf("The elapsed time is %lf seconds\n", timeDif);
	
	time1 = (double) clock();
	
	for(j=0; j<10000000; j++){
		
		x=rand()%100;
		y=cos(x);
	}
	
	
	timeDif = ((double) clock() - time1)/CLOCKS_PER_SEC;

	printf("The elapsed time is %lf seconds\n", timeDif);
    return 0;
}