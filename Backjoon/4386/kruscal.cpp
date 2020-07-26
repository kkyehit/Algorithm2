#include <stdio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <algorithm>

#define MAX_N 100

using namespace std;

struct node{
	int x, y;
	double val;
	node(int _x, int _y, double _val) : x{_x}, y{_y}, val{_val} {}
	bool operator < ( const node &n){
		return this->val < n.val;
	}
}typedef node;

int n;
int group[MAX_N];
pair<double, double> point[MAX_N];
vector<node> edge;
double total;

int getGroup(int a){
	if(group[a] == a) return a;
	return group[a] = getGroup(group[a]);
}

bool setGroup(int _a, int _b){
	int a = getGroup(_a), b = getGroup(_b);
	if(a == b) return false;
	
	if(a < b) {
		group[b] = group[_b] = a;
	}
	else {
		group[a] = group[_a] = b;
	}
	
	return true;
}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		double a, b;
		scanf("%lf %lf", &a, &b);
		point[i] = make_pair(a, b);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			edge.push_back(node(i, j, sqrt( (point[i].first - point[j].first)*(point[i].first - point[j].first) 
										   + (point[i].second - point[j].second)*(point[i].second - point[j].second) ) ) );
		}
	}
	sort(edge.begin(), edge.end());
	
	for(int i = 0; i < n; i++) group[i] = i;
	
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