#include <stdio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <queue>

#define MAX_N 100

using namespace std;
int n;
pair<double, double> point[MAX_N];
double map[MAX_N][MAX_N];
double total;

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		double a, b;
		scanf("%lf %lf", &a, &b);
		point[i] = make_pair(a, b);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			map[i][j] = sqrt( (point[i].first - point[j].first)*(point[i].first - point[j].first) 
										   + (point[i].second - point[j].second)*(point[i].second - point[j].second) ) ) );
		}
	}
	
	total = 0;
	int eSize = edge.size();
	for(int i = 0; i < eSize; i++){
		int x = edge[i].x, y = edge[i].y;
		if(setGroup(x, y)){
			total += edge[i].val;
		}
	}
	printf("%.2lf\n",total);
}