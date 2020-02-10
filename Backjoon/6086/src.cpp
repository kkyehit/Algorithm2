#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_N 700
#define MAX_ALPA 52
#define INF 2123456789

using namespace std;

int N;
int capacity[MAX_ALPA][MAX_ALPA];
int flow[MAX_ALPA][MAX_ALPA];

const int startPoint = 26, endPoint = 51;

/*에드먼드-카프(Edmond-Karp) 알고리즘*/
int networkFlow(){
	int totalFlow = 0;//결과값 저장
	while(true){
		vector<int> p(MAX_ALPA, -1); 	 // p[i] = i정점 까지 도달하게 한 정점의 번호
		queue<int> q;				 	 // q.front() = 방문할 정점
		p[startPoint]=startPoint;		 // start부터 시작한다. start 이전의 정점은 start이다.
		q.push(startPoint);				 // q에 start 추가하여 start부터 탐색한다.
		
		while(!q.empty() && p[endPoint] == -1){	// 큐가 비어있지 않고 아직 end를 방문하지 않았다면 수행
			int now = q.front();				// now = 지금 탐색할 정점
			q.pop();							// 큐의 front에서 제거
			for(int next = 0; next < MAX_ALPA; next++){
				/*next = now에서 갈 수 있는 정점*/
				/*next에 유량을 보낼 수 있다면*/
				if(capacity[now][next] - flow[now][next] > 0 && p[next] == -1){
					p[next] = now;	// next이전은 now
					q.push(next);	// 큐에 next 추가
				}
			}
		}
		/*end에 유량을 보낼 수 없다면 종료*/
		if(p[endPoint] == -1) break;
		
		/*경로 상에서 가장 작은 유량 찾기*/
		int amount = INF;
		for(int i = endPoint; i != startPoint; i = p[i]) 
			amount = min(capacity[p[i]][i] - flow[p[i]][i], amount);
		/*경로에 존재하는 간선의 유량 갱신*/
		for(int i = endPoint; i != startPoint; i = p[i]) {
			flow[p[i]][i] += amount;  // flow에 보낸 유량을 더한다.
			flow[i][p[i]] -= amount;  // 역 방향으로 유량추가
		}
		totalFlow += amount;
	}
	return totalFlow;
}

int main(void){
	char a, b;
	int cost;
	
	memset(capacity, 0, sizeof(capacity));
	memset(flow, 0, sizeof(flow));
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		int numA, numB;
		scanf("%c %c %d\n", &a, &b, &cost);
		numA = ('a'<=a&&a<='z')? a - 'a': a + 26 - 'A'; 
		numB = ('a'<=b&&b<='z')? b - 'a': b + 26 - 'A';
		capacity[numA][numB] += cost;
		capacity[numB][numA] += cost;
	}
	printf("%d\n", networkFlow());
}