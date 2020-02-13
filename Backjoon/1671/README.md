# 열혈강호2
### 11376
***
- 이분 매칭
	- gotEaten[n] : n번쨰 상어를 먹은 상어, 없다면 -1
	- 최대 두마리의 상어를 먹을 수 있으므로 이분 매칭을 두번 수행한다.
- 실패원인
	- 다른 상어 중 같은 크기, 속도, 지능인 상어가 존재할 때 처리를 해야한다.
		+ 먼저 입력된 상어가 먹도록 구현하였다.
	- 처음에 이미 먹힌 상어는 먹지 않도록 구현하여 했는데 문제에 이러한 조건이 없고 다른 상어를 먹는 상어를 먹는다면 이 조건을 구현할 필요가 없다.
***
[문제](https://www.acmicpc.net/problem/11376)
			 