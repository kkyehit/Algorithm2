# Strongly Connected Component
### 2150
***
- 강한 연결 요소 (SCC)
	* SCC
		- 서브 그래프 중 어떤 두 정점 u ,v 를 선택해도 서브그래프 내에 u -> v인 경로가 존재하는 서브그래프
		- 방향성이 없는 그래프는 그래프 자체가 SCC이다.
	* 타잔 알고리즘
		- SCC를 찾는 알고리즘
		- 그래프를 깊이 우선 탐색하며 각 노드마다 도달 가능한 부모노드를 찾는다.
			+ 방문하지 않은 정점이라면 dfs를 이요하여 도달 가능한 제일 높은 노드를 찾고
			+ 방문하지 않은 정점이고 아직 SCC에 포함되지 않았다면 미리 계산했던 도달 가능한 제일 높은 노드이용한다.
		- 더 이상 진행할 노드가 없다면 현재 노드의 번호와 도달 가능한 부모 노드의 번호를 비교한다.
			+ 만약 같다면 SCC를 찾은 것이다.
				- stack에서 현재 노드가 나올 떄까지 pop하여 결과에 저장한다.
				- scc에 포함된 정점임을 표시한다.
			+ 만약 같지 않다면 SCC에 포함될 노드가 더 존재하는 것이다.
	* 교차 간선
		- 조상이나 후손이 아닌 노드에 연결되는 간선
		- u->v일 때 v가 이미 SCC라면 u와 v는 같은 SCC가 아니다. 
- [참고한 블로그](https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220802519976&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView) 
	+ 잘 정리되어 있다.
***
[문제](https://www.acmicpc.net/problem/2150)
			 
