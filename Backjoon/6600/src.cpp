#include <stdio.h>
#include <math.h>

#define FI 3.141592653589793
using namespace std;

int main(void){
	
	double x1, y1, x2, y2, x3, y3;
	double a, b, r;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) > 0){
		b = -(2*((x1*x1 - x2*x2 + y1*y1 - y2*y2)*(x3 - x2) - (x2*x2 - x3*x3 + y2*y2 - y3*y3 )*(x2 - x1))) / (4*((y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)));
		a = -(2*((x1*x1 - x2*x2 + y1*y1 - y2*y2)*(y3 - y2) - (x2*x2 - x3*x3 + y2*y2 - y3*y3 )*(y2 - y1))) / (4*((x2 - x1)*(y3 - y2) - (x3 - x2)*(y2 - y1)));
		r = sqrt((x1 - a)*(x1 - a) + (y1 - b)*(y1 - b));
		printf("%0.2lf\n", 2 * r * FI );
	}
}