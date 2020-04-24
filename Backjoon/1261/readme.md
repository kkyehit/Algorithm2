## 알고스팟
- `Dijkstra` 알고리즘으로 마지막 위치까지 최소한의 벽 깨기로 이동할 때 벽을 깬 횟수 출력
- 실패원인
	1. **메모리 초과**
		- 'priority_queue`에 넣기 전 `Cost[][]`를 갱신하여 `priority_queue`에 들어가는 노드의 수를 줄여서 해결
	2. **틀렸습니다.**
		- `n` 과 `m`을 바꿔서 사용함.
		
[문제](https://www.acmicpc.net/problem/1261)