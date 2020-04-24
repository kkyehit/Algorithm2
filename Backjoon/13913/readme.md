## 숨바꼭질4
* `BFS`를 이용하여 `preLocation[now]`에 현제 위치까지 최소한의 비용으로 도달하기 위해 거쳐야 하는 이전 위치를 저장한다.
+ `K` 부터 `시작 위치`에 도달할 때까지 `preLocation[K]` 를 거슬러 올라가면서 `stack`에 저장한 후 `stack`의 최상단 부터 출력한다.
 - `preLocation[]`은 -2로 초기화 하고 시작위치의 이전 위치는 `-1`로 고려하였다.
 	- `preLocation[]`을 -1로 초기화 하면 시작위치가 방문 되었는지 확인 할 수 가 없다.

[문제](https://www.acmicpc.net/problem/13913)