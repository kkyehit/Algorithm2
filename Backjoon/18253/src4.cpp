#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

#define MAX_N 5
#define MAX_M 100000
#define MAX_Q 100000

using namespace std;

typedef long long int int64;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct Query{
	int r1, c1, r2, c2;
	Query(int _r1, int _c1, int _r2, int _c2){
		r1 = _r1; c1 = _c1; r2 = _r2; c2 = _c2;
	}
};


int N, M, Q;
int64 v[MAX_N + 1][MAX_M + 1];
int64 w[MAX_N + 1][MAX_M + 1];
int64 res[MAX_Q + 1];
vector<Query> query;
priority_queue< pair<int64, pair<int , int> >, vector< pair<int64, pair<int , int> > >, greater<pair<int64, pair<int , int> > > > q;

void Dijkstra(int y, int x, int left, int right){
	for(int i = 1; i <= N; i++)
		for(int j = left; j <= right; j++)
			w[i][j] = 1e18;
	
	q.push(make_pair(v[y][x], make_pair(y, x)));
	w[y][x] = v[y][x];
	
	while(!q.empty()){
		int Y = q.top().second.first, X = q.top().second.second;
		int64 W = q.top().first;
		q.pop();
		
		if(w[Y][X] < W) continue;
		
		for(int i = 0; i < 4; i++){
			int nextY = Y + d[i][0], nextX = X + d[i][1];
			if(nextY < 1 || nextY > N) continue;
			if(nextX < left || nextX > right) continue;
			int64 nextW = W + v[nextY][nextX];
			if(nextW < w[nextY][nextX]){
				w[nextY][nextX] = nextW;
				q.push(make_pair(nextW, make_pair(nextY, nextX ) ) );
			}
		}
	}
}

void DivisionAndConquest(int left, int right, vector<int> &list){
	if(list.empty()) return;
	if(right < left) return;
	int mid = (left + right ) >> 1;
	
	//printf("%d %d %d\n", left, right, mid);
	for(int i = 1; i <= N; i++){
		Dijkstra(i, mid, left, right);
		for(auto j : list){
			auto q = query[j];
			res[j] = min(res[j], w[q.r1][q.c1] + w[q.r2][q.c2] - v[i][mid]);
			//printf("res[%d] = %lld\n", j, res[j]);
		}
	}
	
	vector<int> leftList, rightList;
	for(auto j : list){
		if(query[j].c2 < mid) leftList.push_back(j);
		if(mid < query[j].c1) rightList.push_back(j);
	}
	DivisionAndConquest(left, mid - 1, leftList);
	DivisionAndConquest(mid + 1, right, rightList);
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%lld",&v[i][j]);
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		if(c2 < c1){
			swap(c2, c1);
			swap(r2, r1);
		}
		query.push_back(Query(r1, c1, r2, c2));
		res[i] = 1e18;
	}
	
	vector<int> list;
	for(int i = 0; i < Q; i++) list.push_back(i);
	DivisionAndConquest(1, M, list);
	for(int i = 0; i < Q; i++) printf("%lld\n", res[i]);
	
}