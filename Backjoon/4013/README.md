# ATM
### 4013
***
- SCC + 위상정렬
	+ 어떤 점정 u,v 를 선택하여도 u -> v가 존재하는 서브 그래프인 SCC를 구한다.
	+ SCC를 구하면서 그 SCC에서 얻을 수 있는 현금의 합과 은행 포함 여부를 저장한다.
	+ SCC를 모두 구한 후 각각의 SCC에 들어오는 간선의 개수를 저장한다.
	+ 들어오는 간선이 존재하지 않는 SCC부터 탐색을 하여 각 SCC까지의 현금의 합의 최대값을 갱신한다. 이때 주어진 시작점으로부터 도달할 수 있을때만 갱신하며 기본 값은 그 SCC에서 얻을 수 있는 현금의 합이다.
	+ 한 SCC에서 탐색할 수 있는 다른 SCC가 있다면 다른 SCC의 들어가는 간선 수를 감소시키고 이 값이 0이 되면 queue에 추가하여 계속 탐색한다.
	+ 은행이 포함된 SCC중 최대 값을 출력한다.
	
- [참고한 블로그](https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220802519976&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView)
***
[문제](https://www.acmicpc.net/problem/4013)
			 
